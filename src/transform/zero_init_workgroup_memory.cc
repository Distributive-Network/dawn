// Copyright 2021 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/transform/zero_init_workgroup_memory.h"

#include <unordered_map>
#include <utility>

#include "src/program_builder.h"
#include "src/sem/atomic_type.h"
#include "src/sem/function.h"
#include "src/sem/variable.h"
#include "src/utils/get_or_create.h"

namespace tint {
namespace transform {

/// PIMPL state for the ZeroInitWorkgroupMemory transform
struct ZeroInitWorkgroupMemory::State {
  /// The clone context
  CloneContext& ctx;
  /// The built statements
  ast::StatementList& stmts;

  /// Zero() generates the statements required to zero initialize the workgroup
  /// storage expression of type `ty`.
  /// @param ty the expression type
  /// @param get_expr a function that builds the AST nodes for the expression
  void Zero(const sem::Type* ty,
            const std::function<ast::Expression*()>& get_expr) {
    if (CanZero(ty)) {
      auto* var = get_expr();
      auto* zero_init = ctx.dst->Construct(CreateASTTypeFor(&ctx, ty));
      stmts.emplace_back(
          ctx.dst->create<ast::AssignmentStatement>(var, zero_init));
      return;
    }

    if (auto* atomic = ty->As<sem::Atomic>()) {
      auto* zero_init =
          ctx.dst->Construct(CreateASTTypeFor(&ctx, atomic->Type()));
      auto* store = ctx.dst->Call("atomicStore", ctx.dst->AddressOf(get_expr()),
                                  zero_init);
      stmts.emplace_back(ctx.dst->create<ast::CallStatement>(store));
      return;
    }

    if (auto* str = ty->As<sem::Struct>()) {
      for (auto* member : str->Members()) {
        auto name = ctx.Clone(member->Declaration()->symbol());
        Zero(member->Type(),
             [&] { return ctx.dst->MemberAccessor(get_expr(), name); });
      }
      return;
    }

    if (auto* arr = ty->As<sem::Array>()) {
      // TODO(bclayton): If array sizes become pipeline-overridable then this
      // will need to emit code for a loop.
      // See https://github.com/gpuweb/gpuweb/pull/1792
      for (size_t i = 0; i < arr->Count(); i++) {
        Zero(arr->ElemType(), [&] {
          return ctx.dst->IndexAccessor(get_expr(),
                                        static_cast<ProgramBuilder::u32>(i));
        });
      }
      return;
    }

    TINT_UNREACHABLE(Transform, ctx.dst->Diagnostics())
        << "could not zero workgroup type: " << ty->type_name();
  }

  /// @returns true if the type `ty` can be zeroed with a simple zero-value
  /// expression in the form of a type constructor without operands. If
  /// CanZero() returns false, then the type needs to be initialized by
  /// decomposing the initialization into multiple sub-initializations.
  /// @param ty the type to inspect
  static bool CanZero(const sem::Type* ty) {
    if (ty->Is<sem::Atomic>()) {
      return false;
    }
    if (auto* str = ty->As<sem::Struct>()) {
      for (auto* member : str->Members()) {
        if (!CanZero(member->Type())) {
          return false;
        }
      }
    }
    if (auto* arr = ty->As<sem::Array>()) {
      if (!CanZero(arr->ElemType())) {
        return false;
      }
    }
    return true;
  }
};

ZeroInitWorkgroupMemory::ZeroInitWorkgroupMemory() = default;

ZeroInitWorkgroupMemory::~ZeroInitWorkgroupMemory() = default;

Output ZeroInitWorkgroupMemory::Run(const Program* in, const DataMap&) {
  ProgramBuilder out;
  CloneContext ctx(&out, in);

  auto& sem = ctx.src->Sem();

  for (auto* ast_func : in->AST().Functions()) {
    if (!ast_func->IsEntryPoint()) {
      continue;
    }

    // Generate a list of statements to zero initialize each of the workgroup
    // storage variables.
    ast::StatementList stmts;
    auto* func = sem.Get(ast_func);
    for (auto* var : func->ReferencedModuleVariables()) {
      if (var->StorageClass() != ast::StorageClass::kWorkgroup) {
        continue;
      }
      State{ctx, stmts}.Zero(var->Type()->UnwrapRef(), [&] {
        auto var_name = ctx.Clone(var->Declaration()->symbol());
        return ctx.dst->Expr(var_name);
      });
    }

    if (stmts.empty()) {
      continue;  // No workgroup variables to initialize.
    }

    // Scan the entry point for an existing local_invocation_index builtin
    // parameter
    ast::Expression* local_index = nullptr;
    for (auto* param : ast_func->params()) {
      if (auto* builtin = ast::GetDecoration<ast::BuiltinDecoration>(
              param->decorations())) {
        if (builtin->value() == ast::Builtin::kLocalInvocationIndex) {
          local_index = ctx.dst->Expr(ctx.Clone(param->symbol()));
          break;
        }
      }

      if (auto* str = sem.Get(param)->Type()->As<sem::Struct>()) {
        for (auto* member : str->Members()) {
          if (auto* builtin = ast::GetDecoration<ast::BuiltinDecoration>(
                  member->Declaration()->decorations())) {
            if (builtin->value() == ast::Builtin::kLocalInvocationIndex) {
              auto* param_expr = ctx.dst->Expr(ctx.Clone(param->symbol()));
              auto member_name = ctx.Clone(member->Declaration()->symbol());
              local_index = ctx.dst->MemberAccessor(param_expr, member_name);
              break;
            }
          }
        }
      }
    }
    if (!local_index) {
      // No existing local index parameter. Append one to the entry point.
      auto* param = ctx.dst->Param(
          ctx.dst->Symbols().New("local_invocation_index"), ctx.dst->ty.u32(),
          {ctx.dst->Builtin(ast::Builtin::kLocalInvocationIndex)});
      ctx.InsertBack(ast_func->params(), param);
      local_index = ctx.dst->Expr(param->symbol());
    }

    // We only want to zero-initialize the workgroup memory with the first
    // shader invocation. Construct an if statement that holds stmts.
    // TODO(crbug.com/tint/910): We should attempt to optimize this for arrays.
    auto* if_zero_local_index = ctx.dst->create<ast::BinaryExpression>(
        ast::BinaryOp::kEqual, local_index, ctx.dst->Expr(0u));
    auto* if_stmt = ctx.dst->If(if_zero_local_index, ctx.dst->Block(stmts));

    // Insert this if-statement at the top of the entry point.
    ctx.InsertFront(ast_func->body()->statements(), if_stmt);

    // Append a single workgroup barrier after the if statement.
    ctx.InsertFront(
        ast_func->body()->statements(),
        ctx.dst->create<ast::CallStatement>(ctx.dst->Call("workgroupBarrier")));
  }

  ctx.Clone();

  return Output(Program(std::move(out)));
}

}  // namespace transform
}  // namespace tint

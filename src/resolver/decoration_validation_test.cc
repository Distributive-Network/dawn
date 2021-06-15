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

#include "src/ast/access_decoration.h"
#include "src/ast/disable_validation_decoration.h"
#include "src/ast/override_decoration.h"
#include "src/ast/return_statement.h"
#include "src/ast/stage_decoration.h"
#include "src/ast/struct_block_decoration.h"
#include "src/ast/workgroup_decoration.h"
#include "src/resolver/resolver.h"
#include "src/resolver/resolver_test_helper.h"

#include "gmock/gmock.h"

namespace tint {
namespace resolver {

// Helpers and typedefs
template <typename T>
using DataType = builder::DataType<T>;
template <typename T>
using vec2 = builder::vec2<T>;
template <typename T>
using vec3 = builder::vec3<T>;
template <typename T>
using vec4 = builder::vec4<T>;
template <typename T>
using mat2x2 = builder::mat2x2<T>;
template <typename T>
using mat3x3 = builder::mat3x3<T>;
template <typename T>
using mat4x4 = builder::mat4x4<T>;
template <typename T, int ID = 0>
using alias = builder::alias<T, ID>;
template <typename T>
using alias1 = builder::alias1<T>;
template <typename T>
using alias2 = builder::alias2<T>;
template <typename T>
using alias3 = builder::alias3<T>;
using f32 = builder::f32;
using i32 = builder::i32;
using u32 = builder::u32;

namespace DecorationTests {
namespace {

enum class DecorationKind {
  kAlign,
  kBinding,
  kBuiltin,
  kGroup,
  kLocation,
  kOverride,
  kOffset,
  kSize,
  kStage,
  kStride,
  kStructBlock,
  kWorkgroup,

  kBindingAndGroup,
};

bool IsBindingDecoration(DecorationKind kind) {
  switch (kind) {
    case DecorationKind::kBinding:
    case DecorationKind::kGroup:
    case DecorationKind::kBindingAndGroup:
      return true;
    default:
      return false;
  }
}

struct TestParams {
  DecorationKind kind;
  bool should_pass;
};
struct TestWithParams : ResolverTestWithParam<TestParams> {};

static ast::DecorationList createDecorations(const Source& source,
                                             ProgramBuilder& builder,
                                             DecorationKind kind) {
  switch (kind) {
    case DecorationKind::kAlign:
      return {builder.create<ast::StructMemberAlignDecoration>(source, 4u)};
    case DecorationKind::kBinding:
      return {builder.create<ast::BindingDecoration>(source, 1u)};
    case DecorationKind::kBuiltin:
      return {builder.Builtin(source, ast::Builtin::kPosition)};
    case DecorationKind::kGroup:
      return {builder.create<ast::GroupDecoration>(source, 1u)};
    case DecorationKind::kLocation:
      return {builder.Location(source, 1)};
    case DecorationKind::kOverride:
      return {builder.create<ast::OverrideDecoration>(source, 0u)};
    case DecorationKind::kOffset:
      return {builder.create<ast::StructMemberOffsetDecoration>(source, 4u)};
    case DecorationKind::kSize:
      return {builder.create<ast::StructMemberSizeDecoration>(source, 4u)};
    case DecorationKind::kStage:
      return {builder.Stage(source, ast::PipelineStage::kCompute)};
    case DecorationKind::kStride:
      return {builder.create<ast::StrideDecoration>(source, 4u)};
    case DecorationKind::kStructBlock:
      return {builder.create<ast::StructBlockDecoration>(source)};
    case DecorationKind::kWorkgroup:
      return {
          builder.create<ast::WorkgroupDecoration>(source, builder.Expr(1))};
    case DecorationKind::kBindingAndGroup:
      return {builder.create<ast::BindingDecoration>(source, 1u),
              builder.create<ast::GroupDecoration>(source, 1u)};
  }
  return {};
}

using FunctionReturnTypeDecorationTest = TestWithParams;
TEST_P(FunctionReturnTypeDecorationTest, IsValid) {
  auto& params = GetParam();

  Func("main", ast::VariableList{}, ty.f32(), ast::StatementList{Return(1.f)},
       ast::DecorationList{Stage(ast::PipelineStage::kCompute)},
       createDecorations({}, *this, params.kind));

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    EXPECT_EQ(r()->error(),
              "error: decoration is not valid for function return types");
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    FunctionReturnTypeDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, false},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, true},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, true},
                    TestParams{DecorationKind::kOverride, false},
                    TestParams{DecorationKind::kOffset, false},
                    TestParams{DecorationKind::kSize, false},
                    TestParams{DecorationKind::kStage, false},
                    TestParams{DecorationKind::kStride, false},
                    TestParams{DecorationKind::kStructBlock, false},
                    TestParams{DecorationKind::kWorkgroup, false},
                    TestParams{DecorationKind::kBindingAndGroup, false}));

TEST_F(FunctionReturnTypeDecorationTest, DuplicateDecoration) {
  Func("main", ast::VariableList{}, ty.f32(), ast::StatementList{Return(1.f)},
       ast::DecorationList{Stage(ast::PipelineStage::kCompute)},
       ast::DecorationList{
           Location(Source{{12, 34}}, 2),
           Location(Source{{56, 78}}, 3),
       });

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate location decoration
12:34 note: first decoration declared here)");
}

using ArrayDecorationTest = TestWithParams;
TEST_P(ArrayDecorationTest, IsValid) {
  auto& params = GetParam();

  auto* arr = ty.array(ty.f32(), 0,
                       createDecorations(Source{{12, 34}}, *this, params.kind));
  Structure("mystruct",
            {
                Member("a", arr),
            },
            {create<ast::StructBlockDecoration>()});

  WrapInFunction();

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    EXPECT_EQ(r()->error(),
              "12:34 error: decoration is not valid for array types");
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    ArrayDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, false},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, false},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, false},
                    TestParams{DecorationKind::kOverride, false},
                    TestParams{DecorationKind::kOffset, false},
                    TestParams{DecorationKind::kSize, false},
                    TestParams{DecorationKind::kStage, false},
                    TestParams{DecorationKind::kStride, true},
                    TestParams{DecorationKind::kStructBlock, false},
                    TestParams{DecorationKind::kWorkgroup, false},
                    TestParams{DecorationKind::kBindingAndGroup, false}));

using StructDecorationTest = TestWithParams;
TEST_P(StructDecorationTest, IsValid) {
  auto& params = GetParam();

  Structure("mystruct", {},
            createDecorations(Source{{12, 34}}, *this, params.kind));

  WrapInFunction();

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    EXPECT_EQ(r()->error(),
              "12:34 error: decoration is not valid for struct declarations");
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    StructDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, false},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, false},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, false},
                    TestParams{DecorationKind::kOverride, false},
                    TestParams{DecorationKind::kOffset, false},
                    TestParams{DecorationKind::kSize, false},
                    TestParams{DecorationKind::kStage, false},
                    TestParams{DecorationKind::kStride, false},
                    TestParams{DecorationKind::kStructBlock, true},
                    TestParams{DecorationKind::kWorkgroup, false},
                    TestParams{DecorationKind::kBindingAndGroup, false}));

TEST_F(StructDecorationTest, DuplicateDecoration) {
  Structure("mystruct",
            {
                Member("a", ty.i32()),
            },
            {
                create<ast::StructBlockDecoration>(Source{{12, 34}}),
                create<ast::StructBlockDecoration>(Source{{56, 78}}),
            });

  WrapInFunction();

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate block decoration
12:34 note: first decoration declared here)");
}

using StructMemberDecorationTest = TestWithParams;
TEST_P(StructMemberDecorationTest, IsValid) {
  auto& params = GetParam();

  ast::StructMemberList members{Member(
      "a", ty.i32(), createDecorations(Source{{12, 34}}, *this, params.kind))};

  Structure("mystruct", members);

  WrapInFunction();

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    EXPECT_EQ(r()->error(),
              "12:34 error: decoration is not valid for structure members");
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    StructMemberDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, true},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, true},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, true},
                    TestParams{DecorationKind::kOverride, false},
                    TestParams{DecorationKind::kOffset, true},
                    TestParams{DecorationKind::kSize, true},
                    TestParams{DecorationKind::kStage, false},
                    TestParams{DecorationKind::kStride, false},
                    TestParams{DecorationKind::kStructBlock, false},
                    TestParams{DecorationKind::kWorkgroup, false},
                    TestParams{DecorationKind::kBindingAndGroup, false}));

TEST_F(StructMemberDecorationTest, DuplicateDecoration) {
  Structure("mystruct", {
                            Member("a", ty.i32(),
                                   {
                                       create<ast::StructMemberAlignDecoration>(
                                           Source{{12, 34}}, 4u),
                                       create<ast::StructMemberAlignDecoration>(
                                           Source{{56, 78}}, 8u),
                                   }),
                        });

  WrapInFunction();

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate align decoration
12:34 note: first decoration declared here)");
}

using VariableDecorationTest = TestWithParams;
TEST_P(VariableDecorationTest, IsValid) {
  auto& params = GetParam();

  if (IsBindingDecoration(params.kind)) {
    Global("a", ty.sampler(ast::SamplerKind::kSampler),
           ast::StorageClass::kNone, nullptr,
           createDecorations(Source{{12, 34}}, *this, params.kind));
  } else {
    Global("a", ty.f32(), ast::StorageClass::kInput, nullptr,
           createDecorations(Source{{12, 34}}, *this, params.kind));
  }

  WrapInFunction();

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    if (!IsBindingDecoration(params.kind)) {
      EXPECT_EQ(r()->error(),
                "12:34 error: decoration is not valid for variables");
    }
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    VariableDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, false},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, true},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, true},
                    TestParams{DecorationKind::kOverride, false},
                    TestParams{DecorationKind::kOffset, false},
                    TestParams{DecorationKind::kSize, false},
                    TestParams{DecorationKind::kStage, false},
                    TestParams{DecorationKind::kStride, false},
                    TestParams{DecorationKind::kStructBlock, false},
                    TestParams{DecorationKind::kWorkgroup, false},
                    TestParams{DecorationKind::kBindingAndGroup, true}));

TEST_F(VariableDecorationTest, DuplicateDecoration) {
  Global("a", ty.sampler(ast::SamplerKind::kSampler),
         ast::DecorationList{
             create<ast::BindingDecoration>(Source{{12, 34}}, 2),
             create<ast::GroupDecoration>(2),
             create<ast::BindingDecoration>(Source{{56, 78}}, 3),
         });

  WrapInFunction();

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate binding decoration
12:34 note: first decoration declared here)");
}

TEST_F(VariableDecorationTest, DuplicateInternalDecoration) {
  auto* s =
      Param("s", ty.sampler(ast::SamplerKind::kSampler),
            ast::DecorationList{
                create<ast::BindingDecoration>(0),
                create<ast::GroupDecoration>(0),
                ASTNodes().Create<ast::DisableValidationDecoration>(
                    ID(), ast::DisabledValidation::kBindingPointCollision),
                ASTNodes().Create<ast::DisableValidationDecoration>(
                    ID(), ast::DisabledValidation::kEntryPointParameter),
            });
  Func("f", {s}, ty.void_(), {});

  EXPECT_TRUE(r()->Resolve()) << r()->error();
}

using ConstantDecorationTest = TestWithParams;
TEST_P(ConstantDecorationTest, IsValid) {
  auto& params = GetParam();

  GlobalConst("a", ty.f32(), Expr(1.23f),
              createDecorations(Source{{12, 34}}, *this, params.kind));

  WrapInFunction();

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    EXPECT_EQ(r()->error(),
              "12:34 error: decoration is not valid for constants");
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    ConstantDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, false},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, false},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, false},
                    TestParams{DecorationKind::kOverride, true},
                    TestParams{DecorationKind::kOffset, false},
                    TestParams{DecorationKind::kSize, false},
                    TestParams{DecorationKind::kStage, false},
                    TestParams{DecorationKind::kStride, false},
                    TestParams{DecorationKind::kStructBlock, false},
                    TestParams{DecorationKind::kWorkgroup, false},
                    TestParams{DecorationKind::kBindingAndGroup, false}));

TEST_F(ConstantDecorationTest, DuplicateDecoration) {
  GlobalConst("a", ty.f32(), Expr(1.23f),
              ast::DecorationList{
                  create<ast::OverrideDecoration>(Source{{12, 34}}),
                  create<ast::OverrideDecoration>(Source{{56, 78}}, 1),
              });

  WrapInFunction();

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate override decoration
12:34 note: first decoration declared here)");
}

using FunctionDecorationTest = TestWithParams;
TEST_P(FunctionDecorationTest, IsValid) {
  auto& params = GetParam();

  ast::DecorationList decos =
      createDecorations(Source{{12, 34}}, *this, params.kind);
  Func("foo", ast::VariableList{}, ty.void_(), ast::StatementList{}, decos);

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve()) << r()->error();
    EXPECT_EQ(r()->error(),
              "12:34 error: decoration is not valid for functions");
  }
}
INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    FunctionDecorationTest,
    testing::Values(TestParams{DecorationKind::kAlign, false},
                    TestParams{DecorationKind::kBinding, false},
                    TestParams{DecorationKind::kBuiltin, false},
                    TestParams{DecorationKind::kGroup, false},
                    TestParams{DecorationKind::kLocation, false},
                    TestParams{DecorationKind::kOverride, false},
                    TestParams{DecorationKind::kOffset, false},
                    TestParams{DecorationKind::kSize, false},
                    // Skip kStage as we do not apply it in this test
                    TestParams{DecorationKind::kStride, false},
                    TestParams{DecorationKind::kStructBlock, false},
                    // Skip kWorkgroup as this is a different error
                    TestParams{DecorationKind::kBindingAndGroup, false}));

}  // namespace
}  // namespace DecorationTests

namespace ArrayStrideTests {
namespace {

struct Params {
  builder::ast_type_func_ptr create_el_type;
  uint32_t stride;
  bool should_pass;
};

template <typename T>
constexpr Params ParamsFor(uint32_t stride, bool should_pass) {
  return Params{DataType<T>::AST, stride, should_pass};
}

struct TestWithParams : ResolverTestWithParam<Params> {};

using ArrayStrideTest = TestWithParams;
TEST_P(ArrayStrideTest, All) {
  auto& params = GetParam();
  auto* el_ty = params.create_el_type(*this);

  std::stringstream ss;
  ss << "el_ty: " << FriendlyName(el_ty) << ", stride: " << params.stride
     << ", should_pass: " << params.should_pass;
  SCOPED_TRACE(ss.str());

  auto* arr = ty.array(Source{{12, 34}}, el_ty, 4, params.stride);

  Global("myarray", arr, ast::StorageClass::kInput);

  if (params.should_pass) {
    EXPECT_TRUE(r()->Resolve()) << r()->error();
  } else {
    EXPECT_FALSE(r()->Resolve());
    EXPECT_EQ(r()->error(),
              "12:34 error: arrays decorated with the stride attribute must "
              "have a stride that is at least the size of the element type, "
              "and be a multiple of the element type's alignment value.");
  }
}

struct SizeAndAlignment {
  uint32_t size;
  uint32_t align;
};
constexpr SizeAndAlignment default_u32 = {4, 4};
constexpr SizeAndAlignment default_i32 = {4, 4};
constexpr SizeAndAlignment default_f32 = {4, 4};
constexpr SizeAndAlignment default_vec2 = {8, 8};
constexpr SizeAndAlignment default_vec3 = {12, 16};
constexpr SizeAndAlignment default_vec4 = {16, 16};
constexpr SizeAndAlignment default_mat2x2 = {16, 8};
constexpr SizeAndAlignment default_mat3x3 = {48, 16};
constexpr SizeAndAlignment default_mat4x4 = {64, 16};

INSTANTIATE_TEST_SUITE_P(
    ResolverDecorationValidationTest,
    ArrayStrideTest,
    testing::Values(
        // Succeed because stride >= element size (while being multiple of
        // element alignment)
        ParamsFor<u32>(default_u32.size, true),
        ParamsFor<i32>(default_i32.size, true),
        ParamsFor<f32>(default_f32.size, true),
        ParamsFor<vec2<f32>>(default_vec2.size, true),
        // vec3's default size is not a multiple of its alignment
        // ParamsFor<vec3<f32>, default_vec3.size, true},
        ParamsFor<vec4<f32>>(default_vec4.size, true),
        ParamsFor<mat2x2<f32>>(default_mat2x2.size, true),
        ParamsFor<mat3x3<f32>>(default_mat3x3.size, true),
        ParamsFor<mat4x4<f32>>(default_mat4x4.size, true),

        // Fail because stride is < element size
        ParamsFor<u32>(default_u32.size - 1, false),
        ParamsFor<i32>(default_i32.size - 1, false),
        ParamsFor<f32>(default_f32.size - 1, false),
        ParamsFor<vec2<f32>>(default_vec2.size - 1, false),
        ParamsFor<vec3<f32>>(default_vec3.size - 1, false),
        ParamsFor<vec4<f32>>(default_vec4.size - 1, false),
        ParamsFor<mat2x2<f32>>(default_mat2x2.size - 1, false),
        ParamsFor<mat3x3<f32>>(default_mat3x3.size - 1, false),
        ParamsFor<mat4x4<f32>>(default_mat4x4.size - 1, false),

        // Succeed because stride equals multiple of element alignment
        ParamsFor<u32>(default_u32.align * 7, true),
        ParamsFor<i32>(default_i32.align * 7, true),
        ParamsFor<f32>(default_f32.align * 7, true),
        ParamsFor<vec2<f32>>(default_vec2.align * 7, true),
        ParamsFor<vec3<f32>>(default_vec3.align * 7, true),
        ParamsFor<vec4<f32>>(default_vec4.align * 7, true),
        ParamsFor<mat2x2<f32>>(default_mat2x2.align * 7, true),
        ParamsFor<mat3x3<f32>>(default_mat3x3.align * 7, true),
        ParamsFor<mat4x4<f32>>(default_mat4x4.align * 7, true),

        // Fail because stride is not multiple of element alignment
        ParamsFor<u32>((default_u32.align - 1) * 7, false),
        ParamsFor<i32>((default_i32.align - 1) * 7, false),
        ParamsFor<f32>((default_f32.align - 1) * 7, false),
        ParamsFor<vec2<f32>>((default_vec2.align - 1) * 7, false),
        ParamsFor<vec3<f32>>((default_vec3.align - 1) * 7, false),
        ParamsFor<vec4<f32>>((default_vec4.align - 1) * 7, false),
        ParamsFor<mat2x2<f32>>((default_mat2x2.align - 1) * 7, false),
        ParamsFor<mat3x3<f32>>((default_mat3x3.align - 1) * 7, false),
        ParamsFor<mat4x4<f32>>((default_mat4x4.align - 1) * 7, false)));

TEST_F(ArrayStrideTest, DuplicateDecoration) {
  auto* arr = ty.array(Source{{12, 34}}, ty.i32(), 4,
                       {
                           create<ast::StrideDecoration>(Source{{12, 34}}, 4),
                           create<ast::StrideDecoration>(Source{{56, 78}}, 4),
                       });

  Global("myarray", arr, ast::StorageClass::kInput);

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate stride decoration
12:34 note: first decoration declared here)");
}

}  // namespace
}  // namespace ArrayStrideTests

namespace StructBlockTests {
namespace {

using StructBlockTest = ResolverTest;
TEST_F(StructBlockTest, StructUsedAsArrayElement) {
  auto* s = Structure("S", {Member("x", ty.i32())},
                      {create<ast::StructBlockDecoration>()});
  auto* a = ty.array(ty.Of(s), 4);
  Global("G", a, ast::StorageClass::kPrivate);

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "error: A structure type with a [[block]] decoration cannot be "
            "used as an element of an array");
}

}  // namespace
}  // namespace StructBlockTests

namespace ResourceTests {
namespace {

using ResourceDecorationTest = ResolverTest;
TEST_F(ResourceDecorationTest, UniformBufferMissingBinding) {
  auto* s = Structure("S", {Member("x", ty.i32())},
                      {create<ast::StructBlockDecoration>()});
  Global(Source{{12, 34}}, "G", ty.Of(s), ast::StorageClass::kUniform);

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: resource variables require [[group]] and [[binding]] "
            "decorations");
}

TEST_F(ResourceDecorationTest, StorageBufferMissingBinding) {
  auto* s = Structure("S", {Member("x", ty.i32())},
                      {create<ast::StructBlockDecoration>()});
  Global(Source{{12, 34}}, "G", ty.Of(s), ast::StorageClass::kStorage,
         ast::Access::kRead);

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: resource variables require [[group]] and [[binding]] "
            "decorations");
}

TEST_F(ResourceDecorationTest, TextureMissingBinding) {
  Global(Source{{12, 34}}, "G", ty.depth_texture(ast::TextureDimension::k2d),
         ast::StorageClass::kNone);

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: resource variables require [[group]] and [[binding]] "
            "decorations");
}

TEST_F(ResourceDecorationTest, SamplerMissingBinding) {
  Global(Source{{12, 34}}, "G", ty.sampler(ast::SamplerKind::kSampler),
         ast::StorageClass::kNone);

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: resource variables require [[group]] and [[binding]] "
            "decorations");
}

TEST_F(ResourceDecorationTest, BindingPairMissingBinding) {
  Global(Source{{12, 34}}, "G", ty.sampler(ast::SamplerKind::kSampler),
         ast::StorageClass::kNone,
         ast::DecorationList{
             create<ast::GroupDecoration>(1),
         });

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: resource variables require [[group]] and [[binding]] "
            "decorations");
}

TEST_F(ResourceDecorationTest, BindingPairMissingGroup) {
  Global(Source{{12, 34}}, "G", ty.sampler(ast::SamplerKind::kSampler),
         ast::StorageClass::kNone,
         ast::DecorationList{
             create<ast::BindingDecoration>(1),
         });

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: resource variables require [[group]] and [[binding]] "
            "decorations");
}

TEST_F(ResourceDecorationTest, BindingPointUsedTwiceByEntryPoint) {
  Global(Source{{12, 34}}, "A",
         ty.sampled_texture(ast::TextureDimension::k2d, ty.f32()),
         ast::StorageClass::kNone,
         ast::DecorationList{
             create<ast::BindingDecoration>(1),
             create<ast::GroupDecoration>(2),
         });
  Global(Source{{56, 78}}, "B",
         ty.sampled_texture(ast::TextureDimension::k2d, ty.f32()),
         ast::StorageClass::kNone,
         ast::DecorationList{
             create<ast::BindingDecoration>(1),
             create<ast::GroupDecoration>(2),
         });

  Func("F", {}, ty.void_(),
       {
           Decl(Var("a", ty.vec4<f32>(), ast::StorageClass::kNone,
                    Call("textureLoad", "A", vec2<i32>(1, 2), 0))),
           Decl(Var("b", ty.vec4<f32>(), ast::StorageClass::kNone,
                    Call("textureLoad", "B", vec2<i32>(1, 2), 0))),
       },
       {Stage(ast::PipelineStage::kFragment)});

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(
      r()->error(),
      R"(56:78 error: entry point 'F' references multiple variables that use the same resource binding [[group(2), binding(1)]]
12:34 note: first resource binding usage declared here)");
}

TEST_F(ResourceDecorationTest, BindingPointUsedTwiceByDifferentEntryPoints) {
  Global(Source{{12, 34}}, "A",
         ty.sampled_texture(ast::TextureDimension::k2d, ty.f32()),
         ast::StorageClass::kNone,
         ast::DecorationList{
             create<ast::BindingDecoration>(1),
             create<ast::GroupDecoration>(2),
         });
  Global(Source{{56, 78}}, "B",
         ty.sampled_texture(ast::TextureDimension::k2d, ty.f32()),
         ast::StorageClass::kNone,
         ast::DecorationList{
             create<ast::BindingDecoration>(1),
             create<ast::GroupDecoration>(2),
         });

  Func("F_A", {}, ty.void_(),
       {
           Decl(Var("a", ty.vec4<f32>(), ast::StorageClass::kNone,
                    Call("textureLoad", "A", vec2<i32>(1, 2), 0))),
       },
       {Stage(ast::PipelineStage::kFragment)});
  Func("F_B", {}, ty.void_(),
       {
           Decl(Var("b", ty.vec4<f32>(), ast::StorageClass::kNone,
                    Call("textureLoad", "B", vec2<i32>(1, 2), 0))),
       },
       {Stage(ast::PipelineStage::kFragment)});

  EXPECT_TRUE(r()->Resolve()) << r()->error();
}

TEST_F(ResourceDecorationTest, BindingPointOnNonResource) {
  Global(Source{{12, 34}}, "G", ty.f32(), ast::StorageClass::kPrivate,
         ast::DecorationList{
             create<ast::BindingDecoration>(1),
             create<ast::GroupDecoration>(2),
         });

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: non-resource variables must not have [[group]] or "
            "[[binding]] decorations");
}

}  // namespace
}  // namespace ResourceTests

namespace WorkgroupDecorationTests {
namespace {

using WorkgroupDecoration = ResolverTest;

TEST_F(WorkgroupDecoration, NotAnEntryPoint) {
  Func("main", {}, ty.void_(), {},
       {create<ast::WorkgroupDecoration>(Source{{12, 34}}, Expr(1))});

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: the workgroup_size attribute is only valid for "
            "compute stages");
}

TEST_F(WorkgroupDecoration, NotAComputeShader) {
  Func("main", {}, ty.void_(), {},
       {Stage(ast::PipelineStage::kFragment),
        create<ast::WorkgroupDecoration>(Source{{12, 34}}, Expr(1))});

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            "12:34 error: the workgroup_size attribute is only valid for "
            "compute stages");
}

TEST_F(WorkgroupDecoration, DuplicateDecoration) {
  Func(Source{{12, 34}}, "main", {}, ty.void_(), {},
       {
           Stage(ast::PipelineStage::kCompute),
           WorkgroupSize(Source{{12, 34}}, 1, nullptr, nullptr),
           WorkgroupSize(Source{{56, 78}}, 2, nullptr, nullptr),
       });

  EXPECT_FALSE(r()->Resolve());
  EXPECT_EQ(r()->error(),
            R"(56:78 error: duplicate workgroup_size decoration
12:34 note: first decoration declared here)");
}

}  // namespace
}  // namespace WorkgroupDecorationTests

}  // namespace resolver
}  // namespace tint

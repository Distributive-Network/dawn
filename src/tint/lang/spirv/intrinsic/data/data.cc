// Copyright 2023 The Tint Authors.
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

////////////////////////////////////////////////////////////////////////////////
// File generated by 'tools/src/cmd/gen' using the template:
//   src/tint/lang/spirv/intrinsic/data/data.cc.tmpl
//
// To regenerate run: './tools/run gen'
//
//                       Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

#include <limits>
#include <string>

#include "src/tint/lang/core/intrinsic/data/type_matchers.h"
#include "src/tint/lang/spirv/intrinsic/data/data.h"
#include "src/tint/lang/spirv/intrinsic/data/type_matchers.h"
#include "src/tint/utils/text/string_stream.h"

namespace tint::spirv::intrinsic::data {

using namespace tint::core::intrinsic::data;  // NOLINT(build/namespaces)

namespace {

using ConstEvalFunctionIndex = tint::core::intrinsic::ConstEvalFunctionIndex;
using IntrinsicInfo = tint::core::intrinsic::IntrinsicInfo;
using MatchState = tint::core::intrinsic::MatchState;
using Number = tint::core::intrinsic::Number;
using NumberMatcher = tint::core::intrinsic::NumberMatcher;
using NumberMatcherIndex = tint::core::intrinsic::NumberMatcherIndex;
using NumberMatcherIndicesIndex = tint::core::intrinsic::NumberMatcherIndicesIndex;
using OverloadFlag = tint::core::intrinsic::OverloadFlag;
using OverloadFlags = tint::core::intrinsic::OverloadFlags;
using OverloadIndex = tint::core::intrinsic::OverloadIndex;
using OverloadInfo = tint::core::intrinsic::OverloadInfo;
using ParameterIndex = tint::core::intrinsic::ParameterIndex;
using ParameterInfo = tint::core::intrinsic::ParameterInfo;
using StringStream = tint::StringStream;
using TemplateNumberIndex = tint::core::intrinsic::TemplateNumberIndex;
using TemplateNumberInfo = tint::core::intrinsic::TemplateNumberInfo;
using TemplateTypeIndex = tint::core::intrinsic::TemplateTypeIndex;
using TemplateTypeInfo = tint::core::intrinsic::TemplateTypeInfo;
using Type = tint::core::type::Type;
using TypeMatcher = tint::core::intrinsic::TypeMatcher;
using TypeMatcherIndex = tint::core::intrinsic::TypeMatcherIndex;
using TypeMatcherIndicesIndex = tint::core::intrinsic::TypeMatcherIndicesIndex;

template <size_t N>
using TemplateNumberMatcher = tint::core::intrinsic::TemplateNumberMatcher<N>;

template <size_t N>
using TemplateTypeMatcher = tint::core::intrinsic::TemplateTypeMatcher<N>;

// clang-format off

/// TypeMatcher for 'type f32'
constexpr TypeMatcher kF32Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (!MatchF32(state, ty)) {
      return nullptr;
    }
    return BuildF32(state, ty);
  },
/* string */ [](MatchState*) -> std::string {
    return "f32";
  }
};


/// TypeMatcher for 'type f16'
constexpr TypeMatcher kF16Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (!MatchF16(state, ty)) {
      return nullptr;
    }
    return BuildF16(state, ty);
  },
/* string */ [](MatchState*) -> std::string {
    return "f16";
  }
};


/// TypeMatcher for 'type i32'
constexpr TypeMatcher kI32Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (!MatchI32(state, ty)) {
      return nullptr;
    }
    return BuildI32(state, ty);
  },
/* string */ [](MatchState*) -> std::string {
    return "i32";
  }
};


/// TypeMatcher for 'type u32'
constexpr TypeMatcher kU32Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (!MatchU32(state, ty)) {
      return nullptr;
    }
    return BuildU32(state, ty);
  },
/* string */ [](MatchState*) -> std::string {
    return "u32";
  }
};


/// TypeMatcher for 'type vec2'
constexpr TypeMatcher kVec2Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchVec2(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildVec2(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "vec2<" + T + ">";
  }
};


/// TypeMatcher for 'type vec3'
constexpr TypeMatcher kVec3Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchVec3(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildVec3(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "vec3<" + T + ">";
  }
};


/// TypeMatcher for 'type vec4'
constexpr TypeMatcher kVec4Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchVec4(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildVec4(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "vec4<" + T + ">";
  }
};


/// TypeMatcher for 'type mat2x2'
constexpr TypeMatcher kMat2X2Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat2X2(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat2X2(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat2x2<" + T + ">";
  }
};


/// TypeMatcher for 'type mat2x3'
constexpr TypeMatcher kMat2X3Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat2X3(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat2X3(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat2x3<" + T + ">";
  }
};


/// TypeMatcher for 'type mat2x4'
constexpr TypeMatcher kMat2X4Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat2X4(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat2X4(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat2x4<" + T + ">";
  }
};


/// TypeMatcher for 'type mat3x2'
constexpr TypeMatcher kMat3X2Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat3X2(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat3X2(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat3x2<" + T + ">";
  }
};


/// TypeMatcher for 'type mat3x3'
constexpr TypeMatcher kMat3X3Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat3X3(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat3X3(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat3x3<" + T + ">";
  }
};


/// TypeMatcher for 'type mat3x4'
constexpr TypeMatcher kMat3X4Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat3X4(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat3X4(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat3x4<" + T + ">";
  }
};


/// TypeMatcher for 'type mat4x2'
constexpr TypeMatcher kMat4X2Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat4X2(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat4X2(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat4x2<" + T + ">";
  }
};


/// TypeMatcher for 'type mat4x3'
constexpr TypeMatcher kMat4X3Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat4X3(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat4X3(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat4x3<" + T + ">";
  }
};


/// TypeMatcher for 'type mat4x4'
constexpr TypeMatcher kMat4X4Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchMat4X4(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat4X4(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "mat4x4<" + T + ">";
  }
};


/// TypeMatcher for 'type vec'
constexpr TypeMatcher kVecMatcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  Number N = Number::invalid;
  const Type* T = nullptr;
    if (!MatchVec(state, ty, N, T)) {
      return nullptr;
    }
    N = state.Num(N);
    if (!N.IsValid()) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildVec(state, ty, N, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string N = state->NumName();
  const std::string T = state->TypeName();
    StringStream ss;
    ss << "vec" << N << "<" << T << ">";
    return ss.str();
  }
};


/// TypeMatcher for 'type mat'
constexpr TypeMatcher kMatMatcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  Number N = Number::invalid;
  Number M = Number::invalid;
  const Type* T = nullptr;
    if (!MatchMat(state, ty, N, M, T)) {
      return nullptr;
    }
    N = state.Num(N);
    if (!N.IsValid()) {
      return nullptr;
    }
    M = state.Num(M);
    if (!M.IsValid()) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildMat(state, ty, N, M, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string N = state->NumName();
  const std::string M = state->NumName();
  const std::string T = state->TypeName();
    StringStream ss;
    ss << "mat" << N << "x" << M << "<" << T << ">";
    return ss.str();
  }
};


/// TypeMatcher for 'type atomic'
constexpr TypeMatcher kAtomicMatcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchAtomic(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildAtomic(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "atomic<" + T + ">";
  }
};


/// TypeMatcher for 'type ptr'
constexpr TypeMatcher kPtrMatcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  Number S = Number::invalid;
  const Type* T = nullptr;
  Number A = Number::invalid;
    if (!MatchPtr(state, ty, S, T, A)) {
      return nullptr;
    }
    S = state.Num(S);
    if (!S.IsValid()) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    A = state.Num(A);
    if (!A.IsValid()) {
      return nullptr;
    }
    return BuildPtr(state, ty, S, T, A);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string S = state->NumName();
  const std::string T = state->TypeName();
  const std::string A = state->NumName();
    return "ptr<" + S + ", " + T + ", " + A + ">";
  }
};


/// TypeMatcher for 'type struct_with_runtime_array'
constexpr TypeMatcher kStructWithRuntimeArrayMatcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (!MatchStructWithRuntimeArray(state, ty)) {
      return nullptr;
    }
    return BuildStructWithRuntimeArray(state, ty);
  },
/* string */ [](MatchState*) -> std::string {
    return "struct_with_runtime_array";
  }
};


/// TypeMatcher for 'type __atomic_compare_exchange_result'
constexpr TypeMatcher kAtomicCompareExchangeResultMatcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
  const Type* T = nullptr;
    if (!MatchAtomicCompareExchangeResult(state, ty, T)) {
      return nullptr;
    }
    T = state.Type(T);
    if (T == nullptr) {
      return nullptr;
    }
    return BuildAtomicCompareExchangeResult(state, ty, T);
  },
/* string */ [](MatchState* state) -> std::string {
  const std::string T = state->TypeName();
    return "__atomic_compare_exchange_result<" + T + ">";
  }
};


/// TypeMatcher for 'match f32_f16'
constexpr TypeMatcher kF32F16Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (MatchF32(state, ty)) {
      return BuildF32(state, ty);
    }
    if (MatchF16(state, ty)) {
      return BuildF16(state, ty);
    }
    return nullptr;
  },
/* string */ [](MatchState*) -> std::string {
    StringStream ss;
    // Note: We pass nullptr to the TypeMatcher::String() functions, as 'matcher's do not support
    // template arguments, nor can they match sub-types. As such, they have no use for the MatchState.
    ss << kF32Matcher.string(nullptr) << " or " << kF16Matcher.string(nullptr);
    return ss.str();
  }
};

/// TypeMatcher for 'match iu32'
constexpr TypeMatcher kIu32Matcher {
/* match */ [](MatchState& state, const Type* ty) -> const Type* {
    if (MatchI32(state, ty)) {
      return BuildI32(state, ty);
    }
    if (MatchU32(state, ty)) {
      return BuildU32(state, ty);
    }
    return nullptr;
  },
/* string */ [](MatchState*) -> std::string {
    StringStream ss;
    // Note: We pass nullptr to the TypeMatcher::String() functions, as 'matcher's do not support
    // template arguments, nor can they match sub-types. As such, they have no use for the MatchState.
    ss << kI32Matcher.string(nullptr) << " or " << kU32Matcher.string(nullptr);
    return ss.str();
  }
};

/// EnumMatcher for 'match read_write'
constexpr NumberMatcher kReadWriteMatcher {
/* match */ [](MatchState&, Number number) -> Number {
    if (number.IsAny() || number.Value() == static_cast<uint32_t>(core::Access::kReadWrite)) {
      return Number(static_cast<uint32_t>(core::Access::kReadWrite));
    }
    return Number::invalid;
  },
/* string */ [](MatchState*) -> std::string {
    return "read_write";
  }
};

/// EnumMatcher for 'match storage'
constexpr NumberMatcher kStorageMatcher {
/* match */ [](MatchState&, Number number) -> Number {
    if (number.IsAny() || number.Value() == static_cast<uint32_t>(core::AddressSpace::kStorage)) {
      return Number(static_cast<uint32_t>(core::AddressSpace::kStorage));
    }
    return Number::invalid;
  },
/* string */ [](MatchState*) -> std::string {
    return "storage";
  }
};

/// EnumMatcher for 'match workgroup_or_storage'
constexpr NumberMatcher kWorkgroupOrStorageMatcher {
/* match */ [](MatchState&, Number number) -> Number {
    switch (static_cast<core::AddressSpace>(number.Value())) {
      case core::AddressSpace::kWorkgroup:
      case core::AddressSpace::kStorage:
        return number;
      default:
        return Number::invalid;
    }
  },
/* string */ [](MatchState*) -> std::string {
    return "workgroup or storage";
  }
};

/// Type and number matchers

/// The template types, types, and type matchers
constexpr TypeMatcher kTypeMatchers[] = {
  /* [0] */ TemplateTypeMatcher<0>::matcher,
  /* [1] */ TemplateTypeMatcher<1>::matcher,
  /* [2] */ kF32Matcher,
  /* [3] */ kF16Matcher,
  /* [4] */ kI32Matcher,
  /* [5] */ kU32Matcher,
  /* [6] */ kVec2Matcher,
  /* [7] */ kVec3Matcher,
  /* [8] */ kVec4Matcher,
  /* [9] */ kMat2X2Matcher,
  /* [10] */ kMat2X3Matcher,
  /* [11] */ kMat2X4Matcher,
  /* [12] */ kMat3X2Matcher,
  /* [13] */ kMat3X3Matcher,
  /* [14] */ kMat3X4Matcher,
  /* [15] */ kMat4X2Matcher,
  /* [16] */ kMat4X3Matcher,
  /* [17] */ kMat4X4Matcher,
  /* [18] */ kVecMatcher,
  /* [19] */ kMatMatcher,
  /* [20] */ kAtomicMatcher,
  /* [21] */ kPtrMatcher,
  /* [22] */ kStructWithRuntimeArrayMatcher,
  /* [23] */ kAtomicCompareExchangeResultMatcher,
  /* [24] */ kF32F16Matcher,
  /* [25] */ kIu32Matcher,
};

/// The template numbers, and number matchers
constexpr NumberMatcher kNumberMatchers[] = {
  /* [0] */ TemplateNumberMatcher<0>::matcher,
  /* [1] */ TemplateNumberMatcher<1>::matcher,
  /* [2] */ TemplateNumberMatcher<2>::matcher,
  /* [3] */ kReadWriteMatcher,
  /* [4] */ kStorageMatcher,
  /* [5] */ kWorkgroupOrStorageMatcher,
};

constexpr TypeMatcherIndex kTypeMatcherIndices[] = {
  /* [0] */ TypeMatcherIndex(21),
  /* [1] */ TypeMatcherIndex(20),
  /* [2] */ TypeMatcherIndex(0),
  /* [3] */ TypeMatcherIndex(21),
  /* [4] */ TypeMatcherIndex(22),
  /* [5] */ TypeMatcherIndex(23),
  /* [6] */ TypeMatcherIndex(0),
  /* [7] */ TypeMatcherIndex(19),
  /* [8] */ TypeMatcherIndex(0),
  /* [9] */ TypeMatcherIndex(18),
  /* [10] */ TypeMatcherIndex(0),
  /* [11] */ TypeMatcherIndex(5),
  /* [12] */ TypeMatcherIndex(1),
};

static_assert(TypeMatcherIndex::CanIndex(kTypeMatcherIndices),
              "TypeMatcherIndex is not large enough to index kTypeMatcherIndices");

constexpr NumberMatcherIndex kNumberMatcherIndices[] = {
  /* [0] */ NumberMatcherIndex(4),
  /* [1] */ NumberMatcherIndex(0),
  /* [2] */ NumberMatcherIndex(3),
  /* [3] */ NumberMatcherIndex(1),
  /* [4] */ NumberMatcherIndex(2),
  /* [5] */ NumberMatcherIndex(0),
  /* [6] */ NumberMatcherIndex(2),
  /* [7] */ NumberMatcherIndex(1),
  /* [8] */ NumberMatcherIndex(0),
  /* [9] */ NumberMatcherIndex(1),
};

static_assert(NumberMatcherIndex::CanIndex(kNumberMatcherIndices),
              "NumberMatcherIndex is not large enough to index kNumberMatcherIndices");

constexpr ParameterInfo kParameters[] = {
  {
    /* [0] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(0),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(1),
  },
  {
    /* [1] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(12),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [2] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(12),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [3] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(12),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [4] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [5] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [6] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(0),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(1),
  },
  {
    /* [7] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(12),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [8] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(12),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [9] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [10] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(3),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(0),
  },
  {
    /* [11] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [12] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(5),
  },
  {
    /* [13] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(7),
  },
  {
    /* [14] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(8),
  },
  {
    /* [15] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
  {
    /* [16] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(8),
  },
  {
    /* [17] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(9),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(1),
  },
  {
    /* [18] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(7),
  },
  {
    /* [19] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(9),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(1),
  },
  {
    /* [20] */
    /* usage */ core::ParameterUsage::kNone,
    /* type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
  },
};

static_assert(ParameterIndex::CanIndex(kParameters),
              "ParameterIndex is not large enough to index kParameters");

constexpr TemplateTypeInfo kTemplateTypes[] = {
  {
    /* [0] */
    /* name */ "T",
    /* matcher_index */ TypeMatcherIndex(25),
  },
  {
    /* [1] */
    /* name */ "U",
    /* matcher_index */ TypeMatcherIndex(5),
  },
  {
    /* [2] */
    /* name */ "I",
    /* matcher_index */ TypeMatcherIndex(5),
  },
  {
    /* [3] */
    /* name */ "T",
    /* matcher_index */ TypeMatcherIndex(24),
  },
};

static_assert(TemplateTypeIndex::CanIndex(kTemplateTypes),
              "TemplateTypeIndex is not large enough to index kTemplateTypes");

constexpr TemplateNumberInfo kTemplateNumbers[] = {
  {
    /* [0] */
    /* name */ "K",
    /* matcher_index */ NumberMatcherIndex(/* invalid */),
  },
  {
    /* [1] */
    /* name */ "C",
    /* matcher_index */ NumberMatcherIndex(/* invalid */),
  },
  {
    /* [2] */
    /* name */ "R",
    /* matcher_index */ NumberMatcherIndex(/* invalid */),
  },
  {
    /* [3] */
    /* name */ "N",
    /* matcher_index */ NumberMatcherIndex(/* invalid */),
  },
  {
    /* [4] */
    /* name */ "M",
    /* matcher_index */ NumberMatcherIndex(/* invalid */),
  },
  {
    /* [5] */
    /* name */ "A",
    /* matcher_index */ NumberMatcherIndex(/* invalid */),
  },
  {
    /* [6] */
    /* name */ "S",
    /* matcher_index */ NumberMatcherIndex(5),
  },
};

static_assert(TemplateNumberIndex::CanIndex(kTemplateNumbers),
              "TemplateNumberIndex is not large enough to index kTemplateNumbers");

constexpr OverloadInfo kOverloads[] = {
  {
    /* [0] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsVertexPipeline, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 2,
    /* num_template_types */ 1,
    /* num_template_numbers */ 1,
    /* template_types */ TemplateTypeIndex(2),
    /* template_numbers */ TemplateNumberIndex(5),
    /* parameters */ ParameterIndex(10),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(11),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [1] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 4,
    /* num_template_types */ 2,
    /* num_template_numbers */ 1,
    /* template_types */ TemplateTypeIndex(0),
    /* template_numbers */ TemplateNumberIndex(6),
    /* parameters */ ParameterIndex(6),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [2] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 6,
    /* num_template_types */ 2,
    /* num_template_numbers */ 1,
    /* template_types */ TemplateTypeIndex(0),
    /* template_numbers */ TemplateNumberIndex(6),
    /* parameters */ ParameterIndex(0),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(5),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [3] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 3,
    /* num_template_types */ 2,
    /* num_template_numbers */ 1,
    /* template_types */ TemplateTypeIndex(0),
    /* template_numbers */ TemplateNumberIndex(6),
    /* parameters */ ParameterIndex(0),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(2),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(/* invalid */),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [4] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsVertexPipeline, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 2,
    /* num_template_types */ 1,
    /* num_template_numbers */ 3,
    /* template_types */ TemplateTypeIndex(3),
    /* template_numbers */ TemplateNumberIndex(0),
    /* parameters */ ParameterIndex(12),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(3),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [5] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsVertexPipeline, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 2,
    /* num_template_types */ 1,
    /* num_template_numbers */ 2,
    /* template_types */ TemplateTypeIndex(3),
    /* template_numbers */ TemplateNumberIndex(3),
    /* parameters */ ParameterIndex(14),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(7),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(8),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [6] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsVertexPipeline, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 2,
    /* num_template_types */ 1,
    /* num_template_numbers */ 2,
    /* template_types */ TemplateTypeIndex(3),
    /* template_numbers */ TemplateNumberIndex(3),
    /* parameters */ ParameterIndex(16),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(9),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(3),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [7] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsVertexPipeline, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 2,
    /* num_template_types */ 1,
    /* num_template_numbers */ 2,
    /* template_types */ TemplateTypeIndex(3),
    /* template_numbers */ TemplateNumberIndex(3),
    /* parameters */ ParameterIndex(17),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(9),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(3),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
  {
    /* [8] */
    /* flags */ OverloadFlags(OverloadFlag::kIsBuiltin, OverloadFlag::kSupportsVertexPipeline, OverloadFlag::kSupportsFragmentPipeline, OverloadFlag::kSupportsComputePipeline),
    /* num_parameters */ 2,
    /* num_template_types */ 1,
    /* num_template_numbers */ 1,
    /* template_types */ TemplateTypeIndex(3),
    /* template_numbers */ TemplateNumberIndex(3),
    /* parameters */ ParameterIndex(19),
    /* return_type_matcher_indices */ TypeMatcherIndicesIndex(9),
    /* return_number_matcher_indices */ NumberMatcherIndicesIndex(1),
    /* const_eval_fn */ ConstEvalFunctionIndex(/* invalid */),
  },
};

static_assert(OverloadIndex::CanIndex(kOverloads),
              "OverloadIndex is not large enough to index kOverloads");

constexpr IntrinsicInfo kBuiltins[] = {
  {
    /* [0] */
    /* fn array_length<I : u32, A : access>(ptr<storage, struct_with_runtime_array, A>, I) -> u32 */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(0),
  },
  {
    /* [1] */
    /* fn atomic_and<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [2] */
    /* fn atomic_compare_exchange<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, U, T, T) -> __atomic_compare_exchange_result<T> */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(2),
  },
  {
    /* [3] */
    /* fn atomic_exchange<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [4] */
    /* fn atomic_iadd<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [5] */
    /* fn atomic_isub<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [6] */
    /* fn atomic_load<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(3),
  },
  {
    /* [7] */
    /* fn atomic_or<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [8] */
    /* fn atomic_smax<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [9] */
    /* fn atomic_smin<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [10] */
    /* fn atomic_store<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [11] */
    /* fn atomic_umax<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [12] */
    /* fn atomic_umin<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [13] */
    /* fn atomic_xor<T : iu32, U : u32, S : workgroup_or_storage>(ptr<S, atomic<T>, read_write>, U, U, T) -> T */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(1),
  },
  {
    /* [14] */
    /* fn matrix_times_matrix<T : f32_f16, K : num, C : num, R : num>(mat<K, R, T>, mat<C, K, T>) -> mat<C, R, T> */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(4),
  },
  {
    /* [15] */
    /* fn matrix_times_scalar<T : f32_f16, N : num, M : num>(mat<N, M, T>, T) -> mat<N, M, T> */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(5),
  },
  {
    /* [16] */
    /* fn matrix_times_vector<T : f32_f16, N : num, M : num>(mat<N, M, T>, vec<N, T>) -> vec<M, T> */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(6),
  },
  {
    /* [17] */
    /* fn vector_times_matrix<T : f32_f16, N : num, M : num>(vec<N, T>, mat<M, N, T>) -> vec<M, T> */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(7),
  },
  {
    /* [18] */
    /* fn vector_times_scalar<T : f32_f16, N : num>(vec<N, T>, T) -> vec<N, T> */
    /* num overloads */ 1,
    /* overloads */ OverloadIndex(8),
  },
};

// clang-format on

}  // anonymous namespace

const core::intrinsic::TableData kData{
    /* template_types */ kTemplateTypes,
    /* template_numbers */ kTemplateNumbers,
    /* type_matcher_indices */ kTypeMatcherIndices,
    /* number_matcher_indices */ kNumberMatcherIndices,
    /* type_matchers */ kTypeMatchers,
    /* number_matchers */ kNumberMatchers,
    /* parameters */ kParameters,
    /* overloads */ kOverloads,
    /* const_eval_functions */ Empty,
    /* ctor_conv */ Empty,
    /* builtins */ kBuiltins,
    /* binary '+' */ tint::core::intrinsic::kNoOverloads,
    /* binary '-' */ tint::core::intrinsic::kNoOverloads,
    /* binary '*' */ tint::core::intrinsic::kNoOverloads,
    /* binary '/' */ tint::core::intrinsic::kNoOverloads,
    /* binary '%' */ tint::core::intrinsic::kNoOverloads,
    /* binary '^' */ tint::core::intrinsic::kNoOverloads,
    /* binary '&' */ tint::core::intrinsic::kNoOverloads,
    /* binary '|' */ tint::core::intrinsic::kNoOverloads,
    /* binary '&&' */ tint::core::intrinsic::kNoOverloads,
    /* binary '||' */ tint::core::intrinsic::kNoOverloads,
    /* binary '==' */ tint::core::intrinsic::kNoOverloads,
    /* binary '!=' */ tint::core::intrinsic::kNoOverloads,
    /* binary '<' */ tint::core::intrinsic::kNoOverloads,
    /* binary '>' */ tint::core::intrinsic::kNoOverloads,
    /* binary '<=' */ tint::core::intrinsic::kNoOverloads,
    /* binary '>=' */ tint::core::intrinsic::kNoOverloads,
    /* binary '<<' */ tint::core::intrinsic::kNoOverloads,
    /* binary '>>' */ tint::core::intrinsic::kNoOverloads,
    /* unary '!' */ tint::core::intrinsic::kNoOverloads,
    /* unary '~' */ tint::core::intrinsic::kNoOverloads,
    /* unary '-' */ tint::core::intrinsic::kNoOverloads,
};

}  // namespace tint::spirv::intrinsic::data

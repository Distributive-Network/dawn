// Copyright 2022 The Tint Authors.
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

#include "src/tint/writer/wgsl/test_helper.h"

namespace tint::writer::wgsl {
namespace {

using WgslGeneratorImplTest = TestHelper;

TEST_F(WgslGeneratorImplTest, Emit_Enable) {
    auto* enable = Enable(ast::Extension::kF16);

    GeneratorImpl& gen = Build();

    ASSERT_TRUE(gen.EmitEnable(enable));
    EXPECT_EQ(gen.result(), R"(enable f16;
)");
}

}  // namespace
}  // namespace tint::writer::wgsl

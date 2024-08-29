# Copyright 2023 The Dawn & Tint Authors
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

################################################################################
# File generated by 'tools/src/cmd/gen' using the template:
#   tools/src/cmd/gen/build/BUILD.cmake.tmpl
#
# To regenerate run: './tools/run gen'
#
#                       Do not modify this file directly
################################################################################

include(lang/wgsl/writer/ast_printer/BUILD.cmake)
include(lang/wgsl/writer/ir_to_program/BUILD.cmake)
include(lang/wgsl/writer/raise/BUILD.cmake)
include(lang/wgsl/writer/syntax_tree_printer/BUILD.cmake)

if(TINT_BUILD_WGSL_WRITER)
################################################################################
# Target:    tint_lang_wgsl_writer
# Kind:      lib
# Condition: TINT_BUILD_WGSL_WRITER
################################################################################
tint_add_target(tint_lang_wgsl_writer lib
  lang/wgsl/writer/options.cc
  lang/wgsl/writer/options.h
  lang/wgsl/writer/output.cc
  lang/wgsl/writer/output.h
  lang/wgsl/writer/writer.cc
  lang/wgsl/writer/writer.h
)

tint_target_add_dependencies(tint_lang_wgsl_writer lib
  tint_api_common
  tint_lang_core
  tint_lang_core_constant
  tint_lang_core_ir
  tint_lang_core_type
  tint_lang_wgsl
  tint_lang_wgsl_ast
  tint_lang_wgsl_common
  tint_lang_wgsl_features
  tint_lang_wgsl_program
  tint_lang_wgsl_sem
  tint_lang_wgsl_writer_ir_to_program
  tint_lang_wgsl_writer_raise
  tint_lang_wgsl_writer_syntax_tree_printer
  tint_utils_containers
  tint_utils_diagnostic
  tint_utils_generator
  tint_utils_ice
  tint_utils_id
  tint_utils_macros
  tint_utils_math
  tint_utils_memory
  tint_utils_reflection
  tint_utils_result
  tint_utils_rtti
  tint_utils_symbol
  tint_utils_text
  tint_utils_traits
)

if(TINT_BUILD_WGSL_WRITER)
  tint_target_add_dependencies(tint_lang_wgsl_writer lib
    tint_lang_wgsl_writer_ast_printer
  )
endif(TINT_BUILD_WGSL_WRITER)

endif(TINT_BUILD_WGSL_WRITER)
if(TINT_BUILD_WGSL_WRITER)
################################################################################
# Target:    tint_lang_wgsl_writer_test
# Kind:      test
# Condition: TINT_BUILD_WGSL_WRITER
################################################################################
tint_add_target(tint_lang_wgsl_writer_test test
  lang/wgsl/writer/options_test.cc
  lang/wgsl/writer/writer_test.cc
)

tint_target_add_dependencies(tint_lang_wgsl_writer_test test
  tint_api_common
  tint_lang_core
  tint_lang_core_constant
  tint_lang_core_intrinsic
  tint_lang_core_ir
  tint_lang_core_ir_test
  tint_lang_core_type
  tint_lang_wgsl
  tint_lang_wgsl_ast
  tint_lang_wgsl_common
  tint_lang_wgsl_features
  tint_lang_wgsl_program
  tint_lang_wgsl_sem
  tint_lang_wgsl_writer_ir_to_program
  tint_lang_wgsl_writer_raise
  tint_utils_containers
  tint_utils_diagnostic
  tint_utils_ice
  tint_utils_id
  tint_utils_macros
  tint_utils_math
  tint_utils_memory
  tint_utils_reflection
  tint_utils_result
  tint_utils_rtti
  tint_utils_symbol
  tint_utils_text
  tint_utils_traits
)

tint_target_add_external_dependencies(tint_lang_wgsl_writer_test test
  "gtest"
)

if(TINT_BUILD_WGSL_WRITER)
  tint_target_add_dependencies(tint_lang_wgsl_writer_test test
    tint_lang_wgsl_writer
  )
endif(TINT_BUILD_WGSL_WRITER)

endif(TINT_BUILD_WGSL_WRITER)
if(TINT_BUILD_WGSL_WRITER)
################################################################################
# Target:    tint_lang_wgsl_writer_bench
# Kind:      bench
# Condition: TINT_BUILD_WGSL_WRITER
################################################################################
tint_add_target(tint_lang_wgsl_writer_bench bench
  lang/wgsl/writer/writer_bench.cc
)

tint_target_add_dependencies(tint_lang_wgsl_writer_bench bench
  tint_cmd_bench_bench
  tint_lang_core
  tint_lang_core_constant
  tint_lang_core_type
  tint_lang_wgsl
  tint_lang_wgsl_ast
  tint_lang_wgsl_common
  tint_lang_wgsl_features
  tint_lang_wgsl_program
  tint_lang_wgsl_sem
  tint_lang_wgsl_writer_ir_to_program
  tint_utils_containers
  tint_utils_diagnostic
  tint_utils_ice
  tint_utils_id
  tint_utils_macros
  tint_utils_math
  tint_utils_memory
  tint_utils_reflection
  tint_utils_result
  tint_utils_rtti
  tint_utils_symbol
  tint_utils_text
  tint_utils_traits
)

tint_target_add_external_dependencies(tint_lang_wgsl_writer_bench bench
  "google-benchmark"
)

if(TINT_BUILD_WGSL_WRITER)
  tint_target_add_dependencies(tint_lang_wgsl_writer_bench bench
    tint_lang_wgsl_writer
  )
endif(TINT_BUILD_WGSL_WRITER)

endif(TINT_BUILD_WGSL_WRITER)
if(TINT_BUILD_WGSL_WRITER)
################################################################################
# Target:    tint_lang_wgsl_writer_fuzz
# Kind:      fuzz
# Condition: TINT_BUILD_WGSL_WRITER
################################################################################
tint_add_target(tint_lang_wgsl_writer_fuzz fuzz
)

tint_target_add_dependencies(tint_lang_wgsl_writer_fuzz fuzz
  tint_lang_core
  tint_lang_core_constant
  tint_lang_core_type
  tint_lang_wgsl
  tint_lang_wgsl_ast
  tint_lang_wgsl_common
  tint_lang_wgsl_features
  tint_lang_wgsl_program
  tint_lang_wgsl_sem
  tint_lang_wgsl_writer_ir_to_program
  tint_utils_bytes
  tint_utils_containers
  tint_utils_diagnostic
  tint_utils_ice
  tint_utils_id
  tint_utils_macros
  tint_utils_math
  tint_utils_memory
  tint_utils_reflection
  tint_utils_result
  tint_utils_rtti
  tint_utils_symbol
  tint_utils_text
  tint_utils_traits
)

if(TINT_BUILD_WGSL_READER)
  tint_target_add_sources(tint_lang_wgsl_writer_fuzz fuzz
    "lang/wgsl/writer/writer_fuzz.cc"
  )
  tint_target_add_dependencies(tint_lang_wgsl_writer_fuzz fuzz
    tint_cmd_fuzz_wgsl_fuzz
  )
endif(TINT_BUILD_WGSL_READER)

if(TINT_BUILD_WGSL_WRITER)
  tint_target_add_dependencies(tint_lang_wgsl_writer_fuzz fuzz
    tint_lang_wgsl_writer
  )
endif(TINT_BUILD_WGSL_WRITER)

endif(TINT_BUILD_WGSL_WRITER)
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

if(TINT_BUILD_MSL_WRITER)
################################################################################
# Target:    tint_lang_msl_writer_ast_printer
# Kind:      lib
# Condition: TINT_BUILD_MSL_WRITER
################################################################################
tint_add_target(tint_lang_msl_writer_ast_printer lib
  lang/msl/writer/ast_printer/ast_printer.cc
  lang/msl/writer/ast_printer/ast_printer.h
)

tint_target_add_dependencies(tint_lang_msl_writer_ast_printer lib
  tint_api_common
  tint_lang_core
  tint_lang_core_common
  tint_lang_core_constant
  tint_lang_core_type
  tint_lang_wgsl
  tint_lang_wgsl_ast
  tint_lang_wgsl_ast_transform
  tint_lang_wgsl_features
  tint_lang_wgsl_helpers
  tint_lang_wgsl_program
  tint_lang_wgsl_sem
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

if(TINT_BUILD_MSL_WRITER)
  tint_target_add_dependencies(tint_lang_msl_writer_ast_printer lib
    tint_lang_msl_writer_ast_raise
    tint_lang_msl_writer_common
  )
endif(TINT_BUILD_MSL_WRITER)

endif(TINT_BUILD_MSL_WRITER)
if(TINT_BUILD_MSL_WRITER)
################################################################################
# Target:    tint_lang_msl_writer_ast_printer_test
# Kind:      test
# Condition: TINT_BUILD_MSL_WRITER
################################################################################
tint_add_target(tint_lang_msl_writer_ast_printer_test test
  lang/msl/writer/ast_printer/array_accessor_test.cc
  lang/msl/writer/ast_printer/assign_test.cc
  lang/msl/writer/ast_printer/ast_function_test.cc
  lang/msl/writer/ast_printer/ast_printer_test.cc
  lang/msl/writer/ast_printer/ast_type_test.cc
  lang/msl/writer/ast_printer/binary_test.cc
  lang/msl/writer/ast_printer/bitcast_test.cc
  lang/msl/writer/ast_printer/block_test.cc
  lang/msl/writer/ast_printer/break_test.cc
  lang/msl/writer/ast_printer/builtin_test.cc
  lang/msl/writer/ast_printer/builtin_texture_test.cc
  lang/msl/writer/ast_printer/call_test.cc
  lang/msl/writer/ast_printer/case_test.cc
  lang/msl/writer/ast_printer/cast_test.cc
  lang/msl/writer/ast_printer/const_assert_test.cc
  lang/msl/writer/ast_printer/constructor_test.cc
  lang/msl/writer/ast_printer/continue_test.cc
  lang/msl/writer/ast_printer/discard_test.cc
  lang/msl/writer/ast_printer/helper_test.h
  lang/msl/writer/ast_printer/identifier_test.cc
  lang/msl/writer/ast_printer/if_test.cc
  lang/msl/writer/ast_printer/import_test.cc
  lang/msl/writer/ast_printer/loop_test.cc
  lang/msl/writer/ast_printer/member_accessor_test.cc
  lang/msl/writer/ast_printer/module_constant_test.cc
  lang/msl/writer/ast_printer/return_test.cc
  lang/msl/writer/ast_printer/sanitizer_test.cc
  lang/msl/writer/ast_printer/switch_test.cc
  lang/msl/writer/ast_printer/unary_op_test.cc
  lang/msl/writer/ast_printer/variable_decl_statement_test.cc
)

tint_target_add_dependencies(tint_lang_msl_writer_ast_printer_test test
  tint_api_common
  tint_lang_core
  tint_lang_core_constant
  tint_lang_core_type
  tint_lang_wgsl
  tint_lang_wgsl_ast
  tint_lang_wgsl_ast_test
  tint_lang_wgsl_common
  tint_lang_wgsl_features
  tint_lang_wgsl_program
  tint_lang_wgsl_resolver
  tint_lang_wgsl_sem
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

tint_target_add_external_dependencies(tint_lang_msl_writer_ast_printer_test test
  "gtest"
)

if(TINT_BUILD_MSL_WRITER)
  tint_target_add_dependencies(tint_lang_msl_writer_ast_printer_test test
    tint_lang_msl_writer
    tint_lang_msl_writer_ast_printer
    tint_lang_msl_writer_common
  )
endif(TINT_BUILD_MSL_WRITER)

endif(TINT_BUILD_MSL_WRITER)
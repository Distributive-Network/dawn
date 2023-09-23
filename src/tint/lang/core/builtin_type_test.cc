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

////////////////////////////////////////////////////////////////////////////////
// File generated by 'tools/src/cmd/gen' using the template:
//   src/tint/lang/core/builtin_type_test.cc.tmpl
//
// To regenerate run: './tools/run gen'
//
//                       Do not modify this file directly
////////////////////////////////////////////////////////////////////////////////

#include "src/tint/lang/core/builtin_type.h"

#include <string>

#include "gtest/gtest.h"

#include "src/tint/utils/text/string.h"

namespace tint::core {
namespace {

namespace parse_print_tests {

struct Case {
    const char* string;
    BuiltinType value;
};

inline std::ostream& operator<<(std::ostream& out, Case c) {
    return out << "'" << std::string(c.string) << "'";
}

static constexpr Case kValidCases[] = {
    {"__atomic_compare_exchange_result_i32", BuiltinType::kAtomicCompareExchangeResultI32},
    {"__atomic_compare_exchange_result_u32", BuiltinType::kAtomicCompareExchangeResultU32},
    {"__frexp_result_abstract", BuiltinType::kFrexpResultAbstract},
    {"__frexp_result_f16", BuiltinType::kFrexpResultF16},
    {"__frexp_result_f32", BuiltinType::kFrexpResultF32},
    {"__frexp_result_vec2_abstract", BuiltinType::kFrexpResultVec2Abstract},
    {"__frexp_result_vec2_f16", BuiltinType::kFrexpResultVec2F16},
    {"__frexp_result_vec2_f32", BuiltinType::kFrexpResultVec2F32},
    {"__frexp_result_vec3_abstract", BuiltinType::kFrexpResultVec3Abstract},
    {"__frexp_result_vec3_f16", BuiltinType::kFrexpResultVec3F16},
    {"__frexp_result_vec3_f32", BuiltinType::kFrexpResultVec3F32},
    {"__frexp_result_vec4_abstract", BuiltinType::kFrexpResultVec4Abstract},
    {"__frexp_result_vec4_f16", BuiltinType::kFrexpResultVec4F16},
    {"__frexp_result_vec4_f32", BuiltinType::kFrexpResultVec4F32},
    {"__modf_result_abstract", BuiltinType::kModfResultAbstract},
    {"__modf_result_f16", BuiltinType::kModfResultF16},
    {"__modf_result_f32", BuiltinType::kModfResultF32},
    {"__modf_result_vec2_abstract", BuiltinType::kModfResultVec2Abstract},
    {"__modf_result_vec2_f16", BuiltinType::kModfResultVec2F16},
    {"__modf_result_vec2_f32", BuiltinType::kModfResultVec2F32},
    {"__modf_result_vec3_abstract", BuiltinType::kModfResultVec3Abstract},
    {"__modf_result_vec3_f16", BuiltinType::kModfResultVec3F16},
    {"__modf_result_vec3_f32", BuiltinType::kModfResultVec3F32},
    {"__modf_result_vec4_abstract", BuiltinType::kModfResultVec4Abstract},
    {"__modf_result_vec4_f16", BuiltinType::kModfResultVec4F16},
    {"__modf_result_vec4_f32", BuiltinType::kModfResultVec4F32},
    {"__packed_vec3", BuiltinType::kPackedVec3},
    {"array", BuiltinType::kArray},
    {"atomic", BuiltinType::kAtomic},
    {"bool", BuiltinType::kBool},
    {"f16", BuiltinType::kF16},
    {"f32", BuiltinType::kF32},
    {"i32", BuiltinType::kI32},
    {"mat2x2", BuiltinType::kMat2X2},
    {"mat2x2f", BuiltinType::kMat2X2F},
    {"mat2x2h", BuiltinType::kMat2X2H},
    {"mat2x3", BuiltinType::kMat2X3},
    {"mat2x3f", BuiltinType::kMat2X3F},
    {"mat2x3h", BuiltinType::kMat2X3H},
    {"mat2x4", BuiltinType::kMat2X4},
    {"mat2x4f", BuiltinType::kMat2X4F},
    {"mat2x4h", BuiltinType::kMat2X4H},
    {"mat3x2", BuiltinType::kMat3X2},
    {"mat3x2f", BuiltinType::kMat3X2F},
    {"mat3x2h", BuiltinType::kMat3X2H},
    {"mat3x3", BuiltinType::kMat3X3},
    {"mat3x3f", BuiltinType::kMat3X3F},
    {"mat3x3h", BuiltinType::kMat3X3H},
    {"mat3x4", BuiltinType::kMat3X4},
    {"mat3x4f", BuiltinType::kMat3X4F},
    {"mat3x4h", BuiltinType::kMat3X4H},
    {"mat4x2", BuiltinType::kMat4X2},
    {"mat4x2f", BuiltinType::kMat4X2F},
    {"mat4x2h", BuiltinType::kMat4X2H},
    {"mat4x3", BuiltinType::kMat4X3},
    {"mat4x3f", BuiltinType::kMat4X3F},
    {"mat4x3h", BuiltinType::kMat4X3H},
    {"mat4x4", BuiltinType::kMat4X4},
    {"mat4x4f", BuiltinType::kMat4X4F},
    {"mat4x4h", BuiltinType::kMat4X4H},
    {"ptr", BuiltinType::kPtr},
    {"sampler", BuiltinType::kSampler},
    {"sampler_comparison", BuiltinType::kSamplerComparison},
    {"texture_1d", BuiltinType::kTexture1D},
    {"texture_2d", BuiltinType::kTexture2D},
    {"texture_2d_array", BuiltinType::kTexture2DArray},
    {"texture_3d", BuiltinType::kTexture3D},
    {"texture_cube", BuiltinType::kTextureCube},
    {"texture_cube_array", BuiltinType::kTextureCubeArray},
    {"texture_depth_2d", BuiltinType::kTextureDepth2D},
    {"texture_depth_2d_array", BuiltinType::kTextureDepth2DArray},
    {"texture_depth_cube", BuiltinType::kTextureDepthCube},
    {"texture_depth_cube_array", BuiltinType::kTextureDepthCubeArray},
    {"texture_depth_multisampled_2d", BuiltinType::kTextureDepthMultisampled2D},
    {"texture_external", BuiltinType::kTextureExternal},
    {"texture_multisampled_2d", BuiltinType::kTextureMultisampled2D},
    {"texture_storage_1d", BuiltinType::kTextureStorage1D},
    {"texture_storage_2d", BuiltinType::kTextureStorage2D},
    {"texture_storage_2d_array", BuiltinType::kTextureStorage2DArray},
    {"texture_storage_3d", BuiltinType::kTextureStorage3D},
    {"u32", BuiltinType::kU32},
    {"vec2", BuiltinType::kVec2},
    {"vec2f", BuiltinType::kVec2F},
    {"vec2h", BuiltinType::kVec2H},
    {"vec2i", BuiltinType::kVec2I},
    {"vec2u", BuiltinType::kVec2U},
    {"vec3", BuiltinType::kVec3},
    {"vec3f", BuiltinType::kVec3F},
    {"vec3h", BuiltinType::kVec3H},
    {"vec3i", BuiltinType::kVec3I},
    {"vec3u", BuiltinType::kVec3U},
    {"vec4", BuiltinType::kVec4},
    {"vec4f", BuiltinType::kVec4F},
    {"vec4h", BuiltinType::kVec4H},
    {"vec4i", BuiltinType::kVec4I},
    {"vec4u", BuiltinType::kVec4U},
};

static constexpr Case kInvalidCases[] = {
    {"__atomic_compareexchangeccresult_i32", BuiltinType::kUndefined},
    {"__atoml3_compare_exchane_resulti2", BuiltinType::kUndefined},
    {"__atomic_compare_Vxchange_result_i32", BuiltinType::kUndefined},
    {"__atomic_com1are_exchange_result_u32", BuiltinType::kUndefined},
    {"__atomic_qqompare_exchage_resulJ_u32", BuiltinType::kUndefined},
    {"__atllmic_compare_exchange_result_u377", BuiltinType::kUndefined},
    {"qpp_frexp_resultHHbstract", BuiltinType::kUndefined},
    {"__fep_esulv_abstract", BuiltinType::kUndefined},
    {"__Gbexp_resul_abstract", BuiltinType::kUndefined},
    {"_vfrexp_resiilt_f16", BuiltinType::kUndefined},
    {"__fr8xp_resultWWf16", BuiltinType::kUndefined},
    {"__frxp_result_fMxx", BuiltinType::kUndefined},
    {"gg_fXexp_reslt_f32", BuiltinType::kUndefined},
    {"__frXxpresul_V32", BuiltinType::kUndefined},
    {"__frexp_r3sult_f32", BuiltinType::kUndefined},
    {"__frexpEresult_vec2_abstract", BuiltinType::kUndefined},
    {"__frex_rPPsult_vTTc2_abstract", BuiltinType::kUndefined},
    {"__frexp_resuddt_ec2_xxbstract", BuiltinType::kUndefined},
    {"__frexp_result_ve442_f16", BuiltinType::kUndefined},
    {"_SSfrexp_resulVV_vec2_f16", BuiltinType::kUndefined},
    {"__fRxpRr22sult_vec2_f16", BuiltinType::kUndefined},
    {"__frexp_res9lt_vec_fF2", BuiltinType::kUndefined},
    {"__frexp_result_ve2_f32", BuiltinType::kUndefined},
    {"_OOfrexp_result_VeHRRf32", BuiltinType::kUndefined},
    {"__frexp_reyult_vec3_absract", BuiltinType::kUndefined},
    {"__frexp_re77ulll_vecG_arrnstract", BuiltinType::kUndefined},
    {"__4rexp_result_vec3_00bstract", BuiltinType::kUndefined},
    {"__oorxp_result_vec316", BuiltinType::kUndefined},
    {"zz_frexp_esult_ec3_f16", BuiltinType::kUndefined},
    {"__iirex11_result_vp3_f16", BuiltinType::kUndefined},
    {"__frXXxp_result_vec3_f32", BuiltinType::kUndefined},
    {"__fnnexp99resIIlt_vec3_f355", BuiltinType::kUndefined},
    {"__faSSerrp_result_vHHc3_fY2", BuiltinType::kUndefined},
    {"__freHp_resutve4_abstkkact", BuiltinType::kUndefined},
    {"jfrexpgresult_veRR4_abstrac", BuiltinType::kUndefined},
    {"__frexp_resul_vec4_absbrac", BuiltinType::kUndefined},
    {"_jfrexp_result_vec4_f16", BuiltinType::kUndefined},
    {"__frexp_resultvec4_f16", BuiltinType::kUndefined},
    {"__freqpresultvec4_f16", BuiltinType::kUndefined},
    {"__frexNN_result_vec_f32", BuiltinType::kUndefined},
    {"__frexp_resvvlt_vc4_f3", BuiltinType::kUndefined},
    {"__frexp_esult_vec4_f3QQ", BuiltinType::kUndefined},
    {"rmodf_reffultabstract", BuiltinType::kUndefined},
    {"__jodf_result_abstract", BuiltinType::kUndefined},
    {"_mNNwdf_r2sult8abstract", BuiltinType::kUndefined},
    {"__mdf_result_f16", BuiltinType::kUndefined},
    {"__modrr_result_f16", BuiltinType::kUndefined},
    {"__mGdf_result_f16", BuiltinType::kUndefined},
    {"__modf_resulFF_f32", BuiltinType::kUndefined},
    {"__modf_eult_E3", BuiltinType::kUndefined},
    {"__odf_resurrt_f32", BuiltinType::kUndefined},
    {"__modf_reslt_vec_abstract", BuiltinType::kUndefined},
    {"__modfJJresuDt_Xc2_abstract", BuiltinType::kUndefined},
    {"_modf_reslt_vec28abstrct", BuiltinType::kUndefined},
    {"__odf_reult_vkc211f1", BuiltinType::kUndefined},
    {"__mdf_result_vec2_f16", BuiltinType::kUndefined},
    {"__modf_resuJt_vec2_f6", BuiltinType::kUndefined},
    {"__modf_result_vec2cf32", BuiltinType::kUndefined},
    {"__modf_result_vec2_fO2", BuiltinType::kUndefined},
    {"KK_movvf_result_vec2_ftt__", BuiltinType::kUndefined},
    {"xx_modf_r8sult_vec3_abtr5ct", BuiltinType::kUndefined},
    {"__modf_resuFt_vec3_aqt__act", BuiltinType::kUndefined},
    {"__modf_result_vec3_aqqstrac", BuiltinType::kUndefined},
    {"__odf_33esult_vec3_f1O6", BuiltinType::kUndefined},
    {"_ttm6df_resQQlt_ooec9_f16", BuiltinType::kUndefined},
    {"_modf_resu66t_vec3_f16", BuiltinType::kUndefined},
    {"__mdf_resultOvxc3_f36zz", BuiltinType::kUndefined},
    {"__modf_resuyyt_vec3_f32", BuiltinType::kUndefined},
    {"__mod_resul_vecZHHf32", BuiltinType::kUndefined},
    {"__modf_reqult_44ec4WWbstract", BuiltinType::kUndefined},
    {"__mof_result_vec4_abstrOOct", BuiltinType::kUndefined},
    {"__modYooresult_vh4_bstract", BuiltinType::kUndefined},
    {"__modf_relt_ve4_f16", BuiltinType::kUndefined},
    {"__modf_result_ve4Ff16", BuiltinType::kUndefined},
    {"__modf_result_wec4_f1", BuiltinType::kUndefined},
    {"__Kdff_rGsult_vec4_f2", BuiltinType::kUndefined},
    {"__modf_reKKulq_vec4_f32", BuiltinType::kUndefined},
    {"__modf_resummt3vec4_f3F", BuiltinType::kUndefined},
    {"__packed_ec3", BuiltinType::kUndefined},
    {"__packed_ecq", BuiltinType::kUndefined},
    {"_backed_bbec3", BuiltinType::kUndefined},
    {"iira", BuiltinType::kUndefined},
    {"aqOOy", BuiltinType::kUndefined},
    {"arvvTTy", BuiltinType::kUndefined},
    {"atomFFc", BuiltinType::kUndefined},
    {"aoQ00P", BuiltinType::kUndefined},
    {"atPmic", BuiltinType::kUndefined},
    {"bos77", BuiltinType::kUndefined},
    {"CoRbbl", BuiltinType::kUndefined},
    {"booXX", BuiltinType::kUndefined},
    {"qOOO6", BuiltinType::kUndefined},
    {"fs", BuiltinType::kUndefined},
    {"f1X", BuiltinType::kUndefined},
    {"f3", BuiltinType::kUndefined},
    {"q", BuiltinType::kUndefined},
    {"f322", BuiltinType::kUndefined},
    {"0yz2", BuiltinType::kUndefined},
    {"iVP", BuiltinType::kUndefined},
    {"Cnn", BuiltinType::kUndefined},
    {"AtqqHH2", BuiltinType::kUndefined},
    {"at2x2", BuiltinType::kUndefined},
    {"mafKK", BuiltinType::kUndefined},
    {"ltgg2f", BuiltinType::kUndefined},
    {"mat2xf", BuiltinType::kUndefined},
    {"NTTtcx4f", BuiltinType::kUndefined},
    {"ma7ppl2h", BuiltinType::kUndefined},
    {"mNNt2xg", BuiltinType::kUndefined},
    {"uub2XX2h", BuiltinType::kUndefined},
    {"mt2x3", BuiltinType::kUndefined},
    {"m88xK", BuiltinType::kUndefined},
    {"maqx3", BuiltinType::kUndefined},
    {"m11t2x3f", BuiltinType::kUndefined},
    {"22at2iif", BuiltinType::kUndefined},
    {"at2x377", BuiltinType::kUndefined},
    {"m2t2xNh", BuiltinType::kUndefined},
    {"mVVt2x3h", BuiltinType::kUndefined},
    {"FaWW2w11h", BuiltinType::kUndefined},
    {"matww4", BuiltinType::kUndefined},
    {"mat2D4", BuiltinType::kUndefined},
    {"maKx4", BuiltinType::kUndefined},
    {"mat21PPhf", BuiltinType::kUndefined},
    {"mat24f", BuiltinType::kUndefined},
    {"mYYt2x4f", BuiltinType::kUndefined},
    {"mttHH4kk", BuiltinType::kUndefined},
    {"mat2rr4h", BuiltinType::kUndefined},
    {"WWas2x4h", BuiltinType::kUndefined},
    {"maYx2", BuiltinType::kUndefined},
    {"mq3f2", BuiltinType::kUndefined},
    {"vvafu222", BuiltinType::kUndefined},
    {"t3x2f", BuiltinType::kUndefined},
    {"YYat3f", BuiltinType::kUndefined},
    {"may3x2EYY", BuiltinType::kUndefined},
    {"da3xMoh", BuiltinType::kUndefined},
    {"matMMx2", BuiltinType::kUndefined},
    {"mat3x55h", BuiltinType::kUndefined},
    {"maN3", BuiltinType::kUndefined},
    {"ma33x3", BuiltinType::kUndefined},
    {"mt3x3", BuiltinType::kUndefined},
    {"mm66Issf", BuiltinType::kUndefined},
    {"mat3x1f", BuiltinType::kUndefined},
    {"Xt3x3", BuiltinType::kUndefined},
    {"LatIx3h", BuiltinType::kUndefined},
    {"at3fh", BuiltinType::kUndefined},
    {"mYtURD3", BuiltinType::kUndefined},
    {"mah3x4", BuiltinType::kUndefined},
    {"muqII4", BuiltinType::kUndefined},
    {"mat3xH", BuiltinType::kUndefined},
    {"at3QQvv", BuiltinType::kUndefined},
    {"at66ef", BuiltinType::kUndefined},
    {"ma7O4f", BuiltinType::kUndefined},
    {"m55t3x0DD", BuiltinType::kUndefined},
    {"maH3x4II", BuiltinType::kUndefined},
    {"at3x4", BuiltinType::kUndefined},
    {"ma994x2", BuiltinType::kUndefined},
    {"mWWt4Gt2", BuiltinType::kUndefined},
    {"ay42", BuiltinType::kUndefined},
    {"mt4x2f", BuiltinType::kUndefined},
    {"IIaBB4x2f", BuiltinType::kUndefined},
    {"TTat4x833", BuiltinType::kUndefined},
    {"ddUUnntYYx2h", BuiltinType::kUndefined},
    {"m5CCxxdZ", BuiltinType::kUndefined},
    {"matkkq2h", BuiltinType::kUndefined},
    {"5iitp00", BuiltinType::kUndefined},
    {"mnntIIx3", BuiltinType::kUndefined},
    {"ccaKx", BuiltinType::kUndefined},
    {"m43KK", BuiltinType::kUndefined},
    {"mat66x3f", BuiltinType::kUndefined},
    {"Et4PP3K", BuiltinType::kUndefined},
    {"xxatx3h", BuiltinType::kUndefined},
    {"qat4x3h", BuiltinType::kUndefined},
    {"MMayySrxh", BuiltinType::kUndefined},
    {"uat4", BuiltinType::kUndefined},
    {"tx4", BuiltinType::kUndefined},
    {"ma54FF4", BuiltinType::kUndefined},
    {"rra444z4f", BuiltinType::kUndefined},
    {"matWW", BuiltinType::kUndefined},
    {"CatZJXx4f", BuiltinType::kUndefined},
    {"maPPx4h", BuiltinType::kUndefined},
    {"mat4c4h", BuiltinType::kUndefined},
    {"matPPll6h", BuiltinType::kUndefined},
    {"9tyy", BuiltinType::kUndefined},
    {"ptKK", BuiltinType::kUndefined},
    {"x_", BuiltinType::kUndefined},
    {"ayKer", BuiltinType::kUndefined},
    {"szmpVek", BuiltinType::kUndefined},
    {"sampqeK", BuiltinType::kUndefined},
    {"sampler_comparisn", BuiltinType::kUndefined},
    {"sapler_comparisVVn", BuiltinType::kUndefined},
    {"samplerIcompaAUison", BuiltinType::kUndefined},
    {"jexurbRd", BuiltinType::kUndefined},
    {"exure_YYd", BuiltinType::kUndefined},
    {"exture_1d", BuiltinType::kUndefined},
    {"texxxur_1d", BuiltinType::kUndefined},
    {"tJxucce_2d", BuiltinType::kUndefined},
    {"texure_JJd", BuiltinType::kUndefined},
    {"lDexture_fCC_arraU", BuiltinType::kUndefined},
    {"tegture_2d_array", BuiltinType::kUndefined},
    {"teCCure2d_arra", BuiltinType::kUndefined},
    {"textue_3d", BuiltinType::kUndefined},
    {"tIx__ure_3d", BuiltinType::kUndefined},
    {"texurettPP", BuiltinType::kUndefined},
    {"tddx3ure_cube", BuiltinType::kUndefined},
    {"teKyyur_cube", BuiltinType::kUndefined},
    {"teturecub", BuiltinType::kUndefined},
    {"textinne_c03e_array", BuiltinType::kUndefined},
    {"nextCCruuvcubK_array", BuiltinType::kUndefined},
    {"tXxturellcbe_array", BuiltinType::kUndefined},
    {"tppxture_depth_2d", BuiltinType::kUndefined},
    {"txture_deptww_2d", BuiltinType::kUndefined},
    {"gexturedemmthuu2", BuiltinType::kUndefined},
    {"texmmre_depthaa2daray", BuiltinType::kUndefined},
    {"texture_RRepth_Td_ccZray", BuiltinType::kUndefined},
    {"text88re_depthTOd_array", BuiltinType::kUndefined},
    {"texture_depth_cm00e", BuiltinType::kUndefined},
    {"texture_Bmepth_cube", BuiltinType::kUndefined},
    {"Mextre_ppeph_cube", BuiltinType::kUndefined},
    {"texturOO_depth_cub_array", BuiltinType::kUndefined},
    {"GeGGture_depthcube_array", BuiltinType::kUndefined},
    {"texture11Hdepth_cube_array", BuiltinType::kUndefined},
    {"textu6e_FFepth_multiameeled_2d", BuiltinType::kUndefined},
    {"texture_epth_mltisampled_2d", BuiltinType::kUndefined},
    {"texture_depth_mullKsaiipled_2d", BuiltinType::kUndefined},
    {"texture_extenal", BuiltinType::kUndefined},
    {"IIext99reexvvernal", BuiltinType::kUndefined},
    {"texture_externl", BuiltinType::kUndefined},
    {"texture_mhltisampled_2d", BuiltinType::kUndefined},
    {"texturemPllltisampzzed_2d", BuiltinType::kUndefined},
    {"exture_mltisamed_2d", BuiltinType::kUndefined},
    {"texture_qqtoragff_1", BuiltinType::kUndefined},
    {"textre_JJddorage_1W", BuiltinType::kUndefined},
    {"XXrxture_storae1zz", BuiltinType::kUndefined},
    {"texturestorag2_2d", BuiltinType::kUndefined},
    {"yyNxture_storage_2d", BuiltinType::kUndefined},
    {"etue_storage_2OO", BuiltinType::kUndefined},
    {"reutuPe_storZgeE2d_array", BuiltinType::kUndefined},
    {"texlure_storddeee_d_22rray", BuiltinType::kUndefined},
    {"texture_mtorage_2V_a9ra", BuiltinType::kUndefined},
    {"teII1re_storage_3d", BuiltinType::kUndefined},
    {"texture_storagb_3d", BuiltinType::kUndefined},
    {"texizrestorge73d", BuiltinType::kUndefined},
    {"u3oi", BuiltinType::kUndefined},
    {"3", BuiltinType::kUndefined},
    {"S2", BuiltinType::kUndefined},
    {"e22", BuiltinType::kUndefined},
    {"1eC2", BuiltinType::kUndefined},
    {"vf8c2", BuiltinType::kUndefined},
    {"c2f", BuiltinType::kUndefined},
    {"JJecSSf", BuiltinType::kUndefined},
    {"92f", BuiltinType::kUndefined},
    {"vbbJJ2TT", BuiltinType::kUndefined},
    {"e66h", BuiltinType::kUndefined},
    {"u662h", BuiltinType::kUndefined},
    {"vW2i", BuiltinType::kUndefined},
    {"v2i", BuiltinType::kUndefined},
    {"veci", BuiltinType::kUndefined},
    {"rec2u", BuiltinType::kUndefined},
    {"2ec2B", BuiltinType::kUndefined},
    {"vcBBu", BuiltinType::kUndefined},
    {"veRR", BuiltinType::kUndefined},
    {"VLL0", BuiltinType::kUndefined},
    {"KOe3", BuiltinType::kUndefined},
    {"vgwcf", BuiltinType::kUndefined},
    {"vLphf", BuiltinType::kUndefined},
    {"eiiEf", BuiltinType::kUndefined},
    {"ec3h", BuiltinType::kUndefined},
    {"UU883", BuiltinType::kUndefined},
    {"rrecvvh", BuiltinType::kUndefined},
    {"ecmm", BuiltinType::kUndefined},
    {"vec4j", BuiltinType::kUndefined},
    {"vec3X", BuiltinType::kUndefined},
    {"vec38", BuiltinType::kUndefined},
    {"vecvEE", BuiltinType::kUndefined},
    {"z99ci", BuiltinType::kUndefined},
    {"JJGeQQ4", BuiltinType::kUndefined},
    {"ssec4", BuiltinType::kUndefined},
    {"PecK", BuiltinType::kUndefined},
    {"tpc4f", BuiltinType::kUndefined},
    {"vec", BuiltinType::kUndefined},
    {"MMec4f", BuiltinType::kUndefined},
    {"vJJc40", BuiltinType::kUndefined},
    {"8c", BuiltinType::kUndefined},
    {"vecggKh", BuiltinType::kUndefined},
    {"vecfi", BuiltinType::kUndefined},
    {"vec47Q", BuiltinType::kUndefined},
    {"veY4i", BuiltinType::kUndefined},
    {"keSu", BuiltinType::kUndefined},
    {"n422", BuiltinType::kUndefined},
    {"vFFu", BuiltinType::kUndefined},
};

using BuiltinTypeParseTest = testing::TestWithParam<Case>;

TEST_P(BuiltinTypeParseTest, Parse) {
    const char* string = GetParam().string;
    BuiltinType expect = GetParam().value;
    EXPECT_EQ(expect, ParseBuiltinType(string));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, BuiltinTypeParseTest, testing::ValuesIn(kValidCases));
INSTANTIATE_TEST_SUITE_P(InvalidCases, BuiltinTypeParseTest, testing::ValuesIn(kInvalidCases));

using BuiltinTypePrintTest = testing::TestWithParam<Case>;

TEST_P(BuiltinTypePrintTest, Print) {
    BuiltinType value = GetParam().value;
    const char* expect = GetParam().string;
    EXPECT_EQ(expect, tint::ToString(value));
}

INSTANTIATE_TEST_SUITE_P(ValidCases, BuiltinTypePrintTest, testing::ValuesIn(kValidCases));

}  // namespace parse_print_tests

}  // namespace
}  // namespace tint::core
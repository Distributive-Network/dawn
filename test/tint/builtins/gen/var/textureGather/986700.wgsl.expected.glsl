#version 310 es
precision highp float;
precision highp int;

uniform highp usampler2D arg_1_arg_2;

uvec4 textureGather_986700() {
  vec2 arg_3 = vec2(1.0f);
  uvec4 res = textureGatherOffset(arg_1_arg_2, arg_3, ivec2(1), int(1u));
  return res;
}

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  uvec4 inner;
} prevent_dce;

struct VertexOutput {
  vec4 pos;
  uvec4 prevent_dce;
};

void fragment_main() {
  prevent_dce.inner = textureGather_986700();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

uniform highp usampler2D arg_1_arg_2;

uvec4 textureGather_986700() {
  vec2 arg_3 = vec2(1.0f);
  uvec4 res = textureGatherOffset(arg_1_arg_2, arg_3, ivec2(1), int(1u));
  return res;
}

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  uvec4 inner;
} prevent_dce;

struct VertexOutput {
  vec4 pos;
  uvec4 prevent_dce;
};

void compute_main() {
  prevent_dce.inner = textureGather_986700();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
#version 310 es

layout(location = 0) flat out uvec4 prevent_dce_1;
uniform highp usampler2D arg_1_arg_2;

uvec4 textureGather_986700() {
  vec2 arg_3 = vec2(1.0f);
  uvec4 res = textureGatherOffset(arg_1_arg_2, arg_3, ivec2(1), int(1u));
  return res;
}

struct VertexOutput {
  vec4 pos;
  uvec4 prevent_dce;
};

VertexOutput vertex_main() {
  VertexOutput tint_symbol = VertexOutput(vec4(0.0f, 0.0f, 0.0f, 0.0f), uvec4(0u, 0u, 0u, 0u));
  tint_symbol.pos = vec4(0.0f);
  tint_symbol.prevent_dce = textureGather_986700();
  return tint_symbol;
}

void main() {
  gl_PointSize = 1.0;
  VertexOutput inner_result = vertex_main();
  gl_Position = inner_result.pos;
  prevent_dce_1 = inner_result.prevent_dce;
  gl_Position.y = -(gl_Position.y);
  gl_Position.z = ((2.0f * gl_Position.z) - gl_Position.w);
  return;
}

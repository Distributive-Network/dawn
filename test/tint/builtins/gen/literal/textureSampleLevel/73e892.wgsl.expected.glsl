#version 310 es
precision highp float;
precision highp int;

uniform highp sampler2DShadow arg_0_arg_1;

float textureSampleLevel_73e892() {
  float res = textureLod(arg_0_arg_1, vec3(vec2(1.0f), 0.0f), float(1u));
  return res;
}

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  float inner;
} prevent_dce;

struct VertexOutput {
  vec4 pos;
  float prevent_dce;
};

void fragment_main() {
  prevent_dce.inner = textureSampleLevel_73e892();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

uniform highp sampler2DShadow arg_0_arg_1;

float textureSampleLevel_73e892() {
  float res = textureLod(arg_0_arg_1, vec3(vec2(1.0f), 0.0f), float(1u));
  return res;
}

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  float inner;
} prevent_dce;

struct VertexOutput {
  vec4 pos;
  float prevent_dce;
};

void compute_main() {
  prevent_dce.inner = textureSampleLevel_73e892();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
#version 310 es

layout(location = 0) flat out float prevent_dce_1;
uniform highp sampler2DShadow arg_0_arg_1;

float textureSampleLevel_73e892() {
  float res = textureLod(arg_0_arg_1, vec3(vec2(1.0f), 0.0f), float(1u));
  return res;
}

struct VertexOutput {
  vec4 pos;
  float prevent_dce;
};

VertexOutput vertex_main() {
  VertexOutput tint_symbol = VertexOutput(vec4(0.0f, 0.0f, 0.0f, 0.0f), 0.0f);
  tint_symbol.pos = vec4(0.0f);
  tint_symbol.prevent_dce = textureSampleLevel_73e892();
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

#version 310 es
precision highp float;
precision highp int;

vec4 dpdyFine_d0a648() {
  vec4 arg_0 = vec4(1.0f);
  vec4 res = dFdy(arg_0);
  return res;
}

layout(binding = 0, std430) buffer prevent_dce_block_ssbo {
  vec4 inner;
} prevent_dce;

void fragment_main() {
  prevent_dce.inner = dpdyFine_d0a648();
}

void main() {
  fragment_main();
  return;
}

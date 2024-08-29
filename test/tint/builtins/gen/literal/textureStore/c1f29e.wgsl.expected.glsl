#version 310 es
precision highp float;
precision highp int;

layout(r32f) uniform highp writeonly image2D arg_0;
void textureStore_c1f29e() {
  imageStore(arg_0, ivec2(uvec2(1u, 0u)), vec4(1.0f));
}

void fragment_main() {
  textureStore_c1f29e();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

layout(r32f) uniform highp writeonly image2D arg_0;
void textureStore_c1f29e() {
  imageStore(arg_0, ivec2(uvec2(1u, 0u)), vec4(1.0f));
}

void compute_main() {
  textureStore_c1f29e();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}

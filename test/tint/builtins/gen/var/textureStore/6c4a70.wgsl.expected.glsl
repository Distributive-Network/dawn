#version 310 es
precision highp float;
precision highp int;

layout(r32i) uniform highp iimage2D arg_0;
void textureStore_6c4a70() {
  uvec2 arg_1 = uvec2(1u);
  ivec4 arg_2 = ivec4(1);
  imageStore(arg_0, ivec2(arg_1), arg_2);
}

void fragment_main() {
  textureStore_6c4a70();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

layout(r32i) uniform highp iimage2D arg_0;
void textureStore_6c4a70() {
  uvec2 arg_1 = uvec2(1u);
  ivec4 arg_2 = ivec4(1);
  imageStore(arg_0, ivec2(arg_1), arg_2);
}

void compute_main() {
  textureStore_6c4a70();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}

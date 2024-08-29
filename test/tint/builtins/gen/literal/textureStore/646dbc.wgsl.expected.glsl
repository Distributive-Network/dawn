#version 310 es
precision highp float;
precision highp int;

layout(rgba32i) uniform highp writeonly iimage3D arg_0;
void textureStore_646dbc() {
  imageStore(arg_0, ivec3(1), ivec4(1));
}

void fragment_main() {
  textureStore_646dbc();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

layout(rgba32i) uniform highp writeonly iimage3D arg_0;
void textureStore_646dbc() {
  imageStore(arg_0, ivec3(1), ivec4(1));
}

void compute_main() {
  textureStore_646dbc();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}

#version 310 es

struct mat2x2_f32 {
  vec2 col0;
  vec2 col1;
};

layout(binding = 0, std140) uniform u_block_std140_ubo {
  mat2x2_f32 inner[4];
} u;

layout(binding = 1, std430) buffer s_block_ssbo {
  float inner;
} s;

mat2 conv_mat2x2_f32(mat2x2_f32 val) {
  return mat2(val.col0, val.col1);
}

void f() {
  mat2 t = transpose(conv_mat2x2_f32(u.inner[2u]));
  float l = length(u.inner[0u].col1.yx);
  float a = abs(u.inner[0u].col1.yx[0u]);
  s.inner = ((t[0].x + float(l)) + float(a));
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}

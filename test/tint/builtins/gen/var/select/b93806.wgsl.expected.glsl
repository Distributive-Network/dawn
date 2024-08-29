#version 310 es
precision highp float;
precision highp int;

ivec3 tint_select(ivec3 param_0, ivec3 param_1, bvec3 param_2) {
    return ivec3(param_2[0] ? param_1[0] : param_0[0], param_2[1] ? param_1[1] : param_0[1], param_2[2] ? param_1[2] : param_0[2]);
}


void select_b93806() {
  bvec3 arg_2 = bvec3(true);
  ivec3 res = tint_select(ivec3(1), ivec3(1), arg_2);
}

struct VertexOutput {
  vec4 pos;
};

void fragment_main() {
  select_b93806();
}

void main() {
  fragment_main();
  return;
}
#version 310 es

ivec3 tint_select(ivec3 param_0, ivec3 param_1, bvec3 param_2) {
    return ivec3(param_2[0] ? param_1[0] : param_0[0], param_2[1] ? param_1[1] : param_0[1], param_2[2] ? param_1[2] : param_0[2]);
}


void select_b93806() {
  bvec3 arg_2 = bvec3(true);
  ivec3 res = tint_select(ivec3(1), ivec3(1), arg_2);
}

struct VertexOutput {
  vec4 pos;
};

void compute_main() {
  select_b93806();
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  compute_main();
  return;
}
#version 310 es

ivec3 tint_select(ivec3 param_0, ivec3 param_1, bvec3 param_2) {
    return ivec3(param_2[0] ? param_1[0] : param_0[0], param_2[1] ? param_1[1] : param_0[1], param_2[2] ? param_1[2] : param_0[2]);
}


void select_b93806() {
  bvec3 arg_2 = bvec3(true);
  ivec3 res = tint_select(ivec3(1), ivec3(1), arg_2);
}

struct VertexOutput {
  vec4 pos;
};

VertexOutput vertex_main() {
  VertexOutput tint_symbol = VertexOutput(vec4(0.0f, 0.0f, 0.0f, 0.0f));
  tint_symbol.pos = vec4(0.0f);
  select_b93806();
  return tint_symbol;
}

void main() {
  gl_PointSize = 1.0;
  VertexOutput inner_result = vertex_main();
  gl_Position = inner_result.pos;
  gl_Position.y = -(gl_Position.y);
  gl_Position.z = ((2.0f * gl_Position.z) - gl_Position.w);
  return;
}

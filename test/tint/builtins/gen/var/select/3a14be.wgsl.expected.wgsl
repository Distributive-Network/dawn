fn select_3a14be() {
  const arg_0 = vec2(1);
  const arg_1 = vec2(1);
  var arg_2 = true;
  var res = select(arg_0, arg_1, arg_2);
}

@fragment
fn fragment_main() {
  select_3a14be();
}

@compute @workgroup_size(1)
fn compute_main() {
  select_3a14be();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  select_3a14be();
  return out;
}

fn tan_a0966f() {
  var res = tan(vec4(1.0));
}

@fragment
fn fragment_main() {
  tan_a0966f();
}

@compute @workgroup_size(1)
fn compute_main() {
  tan_a0966f();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  tan_a0966f();
  return out;
}

fn reflect_d7e210() {
  var res = reflect(vec4(1.0), vec4(1.0));
}

@fragment
fn fragment_main() {
  reflect_d7e210();
}

@compute @workgroup_size(1)
fn compute_main() {
  reflect_d7e210();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  reflect_d7e210();
  return out;
}

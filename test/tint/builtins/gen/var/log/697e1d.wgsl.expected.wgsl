fn log_697e1d() {
  const arg_0 = vec4(1.0);
  var res = log(arg_0);
}

@fragment
fn fragment_main() {
  log_697e1d();
}

@compute @workgroup_size(1)
fn compute_main() {
  log_697e1d();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  log_697e1d();
  return out;
}

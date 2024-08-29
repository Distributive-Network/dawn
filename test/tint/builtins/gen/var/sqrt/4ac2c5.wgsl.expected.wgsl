fn sqrt_4ac2c5() {
  const arg_0 = vec4(1.0);
  var res = sqrt(arg_0);
}

@fragment
fn fragment_main() {
  sqrt_4ac2c5();
}

@compute @workgroup_size(1)
fn compute_main() {
  sqrt_4ac2c5();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  sqrt_4ac2c5();
  return out;
}

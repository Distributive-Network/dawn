fn cos_47d768() {
  const arg_0 = vec4(0.0);
  var res = cos(arg_0);
}

@fragment
fn fragment_main() {
  cos_47d768();
}

@compute @workgroup_size(1)
fn compute_main() {
  cos_47d768();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  cos_47d768();
  return out;
}

fn pow_bc91ed() {
  var res = pow(vec2(1.0), vec2(1.0));
}

@fragment
fn fragment_main() {
  pow_bc91ed();
}

@compute @workgroup_size(1)
fn compute_main() {
  pow_bc91ed();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  pow_bc91ed();
  return out;
}

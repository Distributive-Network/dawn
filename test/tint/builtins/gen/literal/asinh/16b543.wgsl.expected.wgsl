fn asinh_16b543() {
  var res = asinh(vec2(1.0));
}

@fragment
fn fragment_main() {
  asinh_16b543();
}

@compute @workgroup_size(1)
fn compute_main() {
  asinh_16b543();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  asinh_16b543();
  return out;
}

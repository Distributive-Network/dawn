fn length_c2c544() {
  var res = length(vec4(0.0));
}

@fragment
fn fragment_main() {
  length_c2c544();
}

@compute @workgroup_size(1)
fn compute_main() {
  length_c2c544();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  length_c2c544();
  return out;
}

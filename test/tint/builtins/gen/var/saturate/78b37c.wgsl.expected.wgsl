fn saturate_78b37c() {
  const arg_0 = 2.0;
  var res = saturate(arg_0);
}

@fragment
fn fragment_main() {
  saturate_78b37c();
}

@compute @workgroup_size(1)
fn compute_main() {
  saturate_78b37c();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  saturate_78b37c();
  return out;
}

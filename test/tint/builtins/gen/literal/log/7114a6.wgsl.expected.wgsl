fn log_7114a6() -> f32 {
  var res : f32 = log(1.0f);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : f32;

@fragment
fn fragment_main() {
  prevent_dce = log_7114a6();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = log_7114a6();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : f32,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = log_7114a6();
  return out;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : f32;

fn fract_fa5c71() -> f32 {
  var res : f32 = fract(1.25f);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = fract_fa5c71();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = fract_fa5c71();
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
  out.prevent_dce = fract_fa5c71();
  return out;
}

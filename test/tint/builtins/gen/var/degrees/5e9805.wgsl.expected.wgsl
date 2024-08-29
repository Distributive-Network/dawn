enable f16;

fn degrees_5e9805() -> f16 {
  var arg_0 = 1.0h;
  var res : f16 = degrees(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : f16;

@fragment
fn fragment_main() {
  prevent_dce = degrees_5e9805();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = degrees_5e9805();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : f16,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = degrees_5e9805();
  return out;
}

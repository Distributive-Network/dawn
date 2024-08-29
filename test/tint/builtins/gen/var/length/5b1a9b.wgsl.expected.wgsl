enable f16;

fn length_5b1a9b() -> f16 {
  var arg_0 = vec4<f16>(0.0h);
  var res : f16 = length(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : f16;

@fragment
fn fragment_main() {
  prevent_dce = length_5b1a9b();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = length_5b1a9b();
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
  out.prevent_dce = length_5b1a9b();
  return out;
}

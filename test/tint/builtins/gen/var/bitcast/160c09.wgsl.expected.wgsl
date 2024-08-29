fn bitcast_160c09() -> vec4<u32> {
  const arg_0 = vec4(1);
  var res : vec4<u32> = bitcast<vec4<u32>>(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<u32>;

@fragment
fn fragment_main() {
  prevent_dce = bitcast_160c09();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = bitcast_160c09();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<u32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = bitcast_160c09();
  return out;
}

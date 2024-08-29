fn bitcast_7e67cc() -> i32 {
  var arg_0 = 1i;
  var res : i32 = bitcast<i32>(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

@fragment
fn fragment_main() {
  prevent_dce = bitcast_7e67cc();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = bitcast_7e67cc();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : i32,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = bitcast_7e67cc();
  return out;
}

fn countTrailingZeros_42fed6() -> i32 {
  var arg_0 = 1i;
  var res : i32 = countTrailingZeros(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

@fragment
fn fragment_main() {
  prevent_dce = countTrailingZeros_42fed6();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = countTrailingZeros_42fed6();
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
  out.prevent_dce = countTrailingZeros_42fed6();
  return out;
}

fn max_85e6bc() -> vec4<i32> {
  var arg_0 = vec4<i32>(1i);
  var arg_1 = vec4<i32>(1i);
  var res : vec4<i32> = max(arg_0, arg_1);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<i32>;

@fragment
fn fragment_main() {
  prevent_dce = max_85e6bc();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = max_85e6bc();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<i32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = max_85e6bc();
  return out;
}

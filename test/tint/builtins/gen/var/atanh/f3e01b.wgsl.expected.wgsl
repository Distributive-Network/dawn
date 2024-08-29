fn atanh_f3e01b() -> vec4<f32> {
  var arg_0 = vec4<f32>(0.5f);
  var res : vec4<f32> = atanh(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f32>;

@fragment
fn fragment_main() {
  prevent_dce = atanh_f3e01b();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = atanh_f3e01b();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = atanh_f3e01b();
  return out;
}

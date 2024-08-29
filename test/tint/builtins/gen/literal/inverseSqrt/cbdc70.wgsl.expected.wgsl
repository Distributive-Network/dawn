enable f16;

fn inverseSqrt_cbdc70() -> vec4<f16> {
  var res : vec4<f16> = inverseSqrt(vec4<f16>(1.0h));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f16>;

@fragment
fn fragment_main() {
  prevent_dce = inverseSqrt_cbdc70();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = inverseSqrt_cbdc70();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<f16>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = inverseSqrt_cbdc70();
  return out;
}

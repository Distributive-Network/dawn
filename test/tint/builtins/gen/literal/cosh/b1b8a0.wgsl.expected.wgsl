enable f16;

fn cosh_b1b8a0() -> vec3<f16> {
  var res : vec3<f16> = cosh(vec3<f16>(0.0h));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec3<f16>;

@fragment
fn fragment_main() {
  prevent_dce = cosh_b1b8a0();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = cosh_b1b8a0();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec3<f16>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = cosh_b1b8a0();
  return out;
}

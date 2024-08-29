enable f16;

fn mix_f1a543() -> vec4<f16> {
  var res : vec4<f16> = mix(vec4<f16>(1.0h), vec4<f16>(1.0h), 1.0h);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f16>;

@fragment
fn fragment_main() {
  prevent_dce = mix_f1a543();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = mix_f1a543();
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
  out.prevent_dce = mix_f1a543();
  return out;
}

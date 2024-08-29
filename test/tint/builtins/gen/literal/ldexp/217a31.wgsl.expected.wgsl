enable f16;

fn ldexp_217a31() -> vec2<f16> {
  var res : vec2<f16> = ldexp(vec2<f16>(1.0h), vec2(1));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec2<f16>;

@fragment
fn fragment_main() {
  prevent_dce = ldexp_217a31();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = ldexp_217a31();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec2<f16>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = ldexp_217a31();
  return out;
}

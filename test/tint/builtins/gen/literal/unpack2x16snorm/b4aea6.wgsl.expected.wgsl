fn unpack2x16snorm_b4aea6() -> vec2<f32> {
  var res : vec2<f32> = unpack2x16snorm(1u);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec2<f32>;

@fragment
fn fragment_main() {
  prevent_dce = unpack2x16snorm_b4aea6();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = unpack2x16snorm_b4aea6();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec2<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = unpack2x16snorm_b4aea6();
  return out;
}

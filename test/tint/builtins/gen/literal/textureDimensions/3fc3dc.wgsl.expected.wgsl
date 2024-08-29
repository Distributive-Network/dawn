@group(1) @binding(0) var arg_0 : texture_2d_array<f32>;

fn textureDimensions_3fc3dc() -> vec2<u32> {
  var res : vec2<u32> = textureDimensions(arg_0, 1u);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec2<u32>;

@fragment
fn fragment_main() {
  prevent_dce = textureDimensions_3fc3dc();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureDimensions_3fc3dc();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec2<u32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = textureDimensions_3fc3dc();
  return out;
}

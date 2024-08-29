@group(1) @binding(0) var arg_0 : texture_multisampled_2d<f32>;

fn textureLoad_f0abad() -> vec4<f32> {
  var res : vec4<f32> = textureLoad(arg_0, vec2<u32>(1u), 1i);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f32>;

@fragment
fn fragment_main() {
  prevent_dce = textureLoad_f0abad();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureLoad_f0abad();
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
  out.prevent_dce = textureLoad_f0abad();
  return out;
}

@group(1) @binding(1) var arg_1 : texture_2d_array<u32>;

@group(1) @binding(2) var arg_2 : sampler;

fn textureGather_ce5578() -> vec4<u32> {
  var res : vec4<u32> = textureGather(1i, arg_1, arg_2, vec2<f32>(1.0f), 1u, vec2<i32>(1i));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<u32>;

@fragment
fn fragment_main() {
  prevent_dce = textureGather_ce5578();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureGather_ce5578();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<u32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = textureGather_ce5578();
  return out;
}

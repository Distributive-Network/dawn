@group(1) @binding(0) var arg_0 : texture_storage_3d<rgba8snorm, read_write>;

fn textureLoad_1bc5ab() -> vec4<f32> {
  var res : vec4<f32> = textureLoad(arg_0, vec3<u32>(1u));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f32>;

@fragment
fn fragment_main() {
  prevent_dce = textureLoad_1bc5ab();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureLoad_1bc5ab();
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
  out.prevent_dce = textureLoad_1bc5ab();
  return out;
}

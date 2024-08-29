@group(1) @binding(0) var arg_0 : texture_storage_3d<rgba16float, read>;

fn textureLoad_589eaa() -> vec4<f32> {
  var res : vec4<f32> = textureLoad(arg_0, vec3<u32>(1u));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f32>;

@fragment
fn fragment_main() {
  prevent_dce = textureLoad_589eaa();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureLoad_589eaa();
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
  out.prevent_dce = textureLoad_589eaa();
  return out;
}

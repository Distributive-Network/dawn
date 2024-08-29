@group(1) @binding(0) var arg_0 : texture_multisampled_2d<i32>;

fn textureLoad_e3d2cc() -> vec4<i32> {
  var res : vec4<i32> = textureLoad(arg_0, vec2<i32>(1i), 1i);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<i32>;

@fragment
fn fragment_main() {
  prevent_dce = textureLoad_e3d2cc();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureLoad_e3d2cc();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<i32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = textureLoad_e3d2cc();
  return out;
}

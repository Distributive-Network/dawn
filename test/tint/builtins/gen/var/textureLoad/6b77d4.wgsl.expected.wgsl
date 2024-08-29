@group(1) @binding(0) var arg_0 : texture_1d<u32>;

fn textureLoad_6b77d4() -> vec4<u32> {
  var arg_1 = 1i;
  var arg_2 = 1u;
  var res : vec4<u32> = textureLoad(arg_0, arg_1, arg_2);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<u32>;

@fragment
fn fragment_main() {
  prevent_dce = textureLoad_6b77d4();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureLoad_6b77d4();
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
  out.prevent_dce = textureLoad_6b77d4();
  return out;
}

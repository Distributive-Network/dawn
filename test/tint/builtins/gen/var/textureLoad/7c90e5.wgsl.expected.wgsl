@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<u32>;

@group(1) @binding(0) var arg_0 : texture_2d_array<u32>;

fn textureLoad_7c90e5() -> vec4<u32> {
  var arg_1 = vec2<i32>(1i);
  var arg_2 = 1i;
  var arg_3 = 1i;
  var res : vec4<u32> = textureLoad(arg_0, arg_1, arg_2, arg_3);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = textureLoad_7c90e5();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureLoad_7c90e5();
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
  out.prevent_dce = textureLoad_7c90e5();
  return out;
}

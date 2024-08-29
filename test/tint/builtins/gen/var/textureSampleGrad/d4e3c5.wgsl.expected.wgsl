@group(1) @binding(0) var arg_0 : texture_2d<f32>;

@group(1) @binding(1) var arg_1 : sampler;

fn textureSampleGrad_d4e3c5() -> vec4<f32> {
  var arg_2 = vec2<f32>(1.0f);
  var arg_3 = vec2<f32>(1.0f);
  var arg_4 = vec2<f32>(1.0f);
  const arg_5 = vec2<i32>(1i);
  var res : vec4<f32> = textureSampleGrad(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f32>;

@fragment
fn fragment_main() {
  prevent_dce = textureSampleGrad_d4e3c5();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureSampleGrad_d4e3c5();
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
  out.prevent_dce = textureSampleGrad_d4e3c5();
  return out;
}

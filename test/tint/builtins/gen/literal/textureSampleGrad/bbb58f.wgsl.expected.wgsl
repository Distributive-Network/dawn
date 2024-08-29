@group(1) @binding(0) var arg_0 : texture_cube_array<f32>;

@group(1) @binding(1) var arg_1 : sampler;

fn textureSampleGrad_bbb58f() -> vec4<f32> {
  var res : vec4<f32> = textureSampleGrad(arg_0, arg_1, vec3<f32>(1.0f), 1u, vec3<f32>(1.0f), vec3<f32>(1.0f));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f32>;

@fragment
fn fragment_main() {
  prevent_dce = textureSampleGrad_bbb58f();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = textureSampleGrad_bbb58f();
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
  out.prevent_dce = textureSampleGrad_bbb58f();
  return out;
}

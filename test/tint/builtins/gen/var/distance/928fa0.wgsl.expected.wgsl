enable f16;

fn distance_928fa0() -> f16 {
  var arg_0 = vec3<f16>(1.0h);
  var arg_1 = vec3<f16>(1.0h);
  var res : f16 = distance(arg_0, arg_1);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : f16;

@fragment
fn fragment_main() {
  prevent_dce = distance_928fa0();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = distance_928fa0();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : f16,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = distance_928fa0();
  return out;
}

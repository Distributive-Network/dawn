enable f16;

@group(0) @binding(0) var<storage, read_write> prevent_dce : f16;

fn exp2_b408e4() -> f16 {
  var arg_0 = 1.0h;
  var res : f16 = exp2(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = exp2_b408e4();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = exp2_b408e4();
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
  out.prevent_dce = exp2_b408e4();
  return out;
}

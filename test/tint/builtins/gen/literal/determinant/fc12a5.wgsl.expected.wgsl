enable f16;

fn determinant_fc12a5() -> f16 {
  var res : f16 = determinant(mat2x2<f16>(1.0h, 1.0h, 1.0h, 1.0h));
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : f16;

@fragment
fn fragment_main() {
  prevent_dce = determinant_fc12a5();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = determinant_fc12a5();
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
  out.prevent_dce = determinant_fc12a5();
  return out;
}

fn any_e755c1() -> i32 {
  var arg_0 = vec3<bool>(true);
  var res : bool = any(arg_0);
  return select(0, 1, all((res == bool())));
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

@fragment
fn fragment_main() {
  prevent_dce = any_e755c1();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = any_e755c1();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : i32,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = any_e755c1();
  return out;
}

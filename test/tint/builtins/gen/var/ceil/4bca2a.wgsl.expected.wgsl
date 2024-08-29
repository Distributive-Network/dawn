enable f16;

fn ceil_4bca2a() -> vec4<f16> {
  var arg_0 = vec4<f16>(1.5h);
  var res : vec4<f16> = ceil(arg_0);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<f16>;

@fragment
fn fragment_main() {
  prevent_dce = ceil_4bca2a();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = ceil_4bca2a();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
  @location(0) @interpolate(flat)
  prevent_dce : vec4<f16>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  out.prevent_dce = ceil_4bca2a();
  return out;
}

enable f16;

fn frexp_ae4a66() {
  var res = frexp(vec3<f16>(1.0h));
}

@fragment
fn fragment_main() {
  frexp_ae4a66();
}

@compute @workgroup_size(1)
fn compute_main() {
  frexp_ae4a66();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  frexp_ae4a66();
  return out;
}

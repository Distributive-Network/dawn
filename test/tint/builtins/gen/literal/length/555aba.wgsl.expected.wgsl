fn length_555aba() {
  var res = length(vec3(0.0));
}

@fragment
fn fragment_main() {
  length_555aba();
}

@compute @workgroup_size(1)
fn compute_main() {
  length_555aba();
}

struct VertexOutput {
  @builtin(position)
  pos : vec4<f32>,
}

@vertex
fn vertex_main() -> VertexOutput {
  var out : VertexOutput;
  out.pos = vec4<f32>();
  length_555aba();
  return out;
}

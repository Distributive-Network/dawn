fn frexp_bf45ae() {
  var res = frexp(vec3(1.0));
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  frexp_bf45ae();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  frexp_bf45ae();
}

@compute @workgroup_size(1)
fn compute_main() {
  frexp_bf45ae();
}

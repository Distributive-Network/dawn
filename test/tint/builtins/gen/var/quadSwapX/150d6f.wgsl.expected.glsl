SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec3<f32>;

fn quadSwapX_150d6f() -> vec3<f32> {
  var arg_0 = vec3<f32>(1.0f);
  var res : vec3<f32> = quadSwapX(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapX_150d6f();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapX_150d6f();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/quadSwapX/150d6f.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec3<f32>;

fn quadSwapX_150d6f() -> vec3<f32> {
  var arg_0 = vec3<f32>(1.0f);
  var res : vec3<f32> = quadSwapX(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapX_150d6f();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapX_150d6f();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/quadSwapX/150d6f.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


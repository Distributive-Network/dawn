SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec3<u32>;

fn quadSwapDiagonal_856536() -> vec3<u32> {
  var arg_0 = vec3<u32>(1u);
  var res : vec3<u32> = quadSwapDiagonal(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapDiagonal_856536();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapDiagonal_856536();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/quadSwapDiagonal/856536.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec3<u32>;

fn quadSwapDiagonal_856536() -> vec3<u32> {
  var arg_0 = vec3<u32>(1u);
  var res : vec3<u32> = quadSwapDiagonal(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapDiagonal_856536();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapDiagonal_856536();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/quadSwapDiagonal/856536.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

fn quadSwapX_1e1086() -> i32 {
  var arg_0 = 1i;
  var res : i32 = quadSwapX(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapX_1e1086();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapX_1e1086();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/quadSwapX/1e1086.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

fn quadSwapX_1e1086() -> i32 {
  var arg_0 = 1i;
  var res : i32 = quadSwapX(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapX_1e1086();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapX_1e1086();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/quadSwapX/1e1086.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


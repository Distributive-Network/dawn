SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

fn subgroupAnd_c6fc92() -> i32 {
  var arg_0 = 1i;
  var res : i32 = subgroupAnd(arg_0);
  return res;
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = subgroupAnd_c6fc92();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/subgroupAnd/c6fc92.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


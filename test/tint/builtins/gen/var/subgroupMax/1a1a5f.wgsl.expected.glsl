SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : f32;

fn subgroupMax_1a1a5f() -> f32 {
  var arg_0 = 1.0f;
  var res : f32 = subgroupMax(arg_0);
  return res;
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = subgroupMax_1a1a5f();
}

Failed to generate: <dawn>/test/tint/builtins/gen/var/subgroupMax/1a1a5f.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


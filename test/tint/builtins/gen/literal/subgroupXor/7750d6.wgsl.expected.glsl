SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : u32;

fn subgroupXor_7750d6() -> u32 {
  var res : u32 = subgroupXor(1u);
  return res;
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = subgroupXor_7750d6();
}

Failed to generate: <dawn>/test/tint/builtins/gen/literal/subgroupXor/7750d6.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


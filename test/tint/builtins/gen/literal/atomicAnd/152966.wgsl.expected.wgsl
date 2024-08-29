struct SB_RW {
  arg_0 : atomic<i32>,
}

@group(0) @binding(1) var<storage, read_write> sb_rw : SB_RW;

fn atomicAnd_152966() -> i32 {
  var res : i32 = atomicAnd(&(sb_rw.arg_0), 1i);
  return res;
}

@group(0) @binding(0) var<storage, read_write> prevent_dce : i32;

@fragment
fn fragment_main() {
  prevent_dce = atomicAnd_152966();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = atomicAnd_152966();
}

enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec4<i32>;

fn quadSwapDiagonal_a665b1() -> vec4<i32> {
  var arg_0 = vec4<i32>(1i);
  var res : vec4<i32> = quadSwapDiagonal(arg_0);
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapDiagonal_a665b1();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapDiagonal_a665b1();
}

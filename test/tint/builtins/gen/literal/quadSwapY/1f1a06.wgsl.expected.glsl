SKIP: INVALID


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec2<f32>;

fn quadSwapY_1f1a06() -> vec2<f32> {
  var res : vec2<f32> = quadSwapY(vec2<f32>(1.0f));
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapY_1f1a06();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapY_1f1a06();
}

Failed to generate: <dawn>/test/tint/builtins/gen/literal/quadSwapY/1f1a06.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


enable subgroups;

@group(0) @binding(0) var<storage, read_write> prevent_dce : vec2<f32>;

fn quadSwapY_1f1a06() -> vec2<f32> {
  var res : vec2<f32> = quadSwapY(vec2<f32>(1.0f));
  return res;
}

@fragment
fn fragment_main() {
  prevent_dce = quadSwapY_1f1a06();
}

@compute @workgroup_size(1)
fn compute_main() {
  prevent_dce = quadSwapY_1f1a06();
}

Failed to generate: <dawn>/test/tint/builtins/gen/literal/quadSwapY/1f1a06.wgsl:41:8 error: GLSL backend does not support extension 'subgroups'
enable subgroups;
       ^^^^^^^^^


@group(1) @binding(0) var arg_0 : texture_storage_1d<rgba32uint, read_write>;

fn textureStore_2173fd() {
  textureStore(arg_0, 1u, vec4<u32>(1u));
}

@fragment
fn fragment_main() {
  textureStore_2173fd();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureStore_2173fd();
}

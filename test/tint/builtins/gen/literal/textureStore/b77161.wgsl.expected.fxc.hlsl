RWTexture1D<uint4> arg_0 : register(u0, space1);

void textureStore_b77161() {
  arg_0[1u] = (1u).xxxx;
}

void fragment_main() {
  textureStore_b77161();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  textureStore_b77161();
  return;
}

RWTexture2D<int4> arg_0 : register(u0, space1);

void textureStore_bcc97a() {
  arg_0[(1).xx] = (1).xxxx;
}

void fragment_main() {
  textureStore_bcc97a();
  return;
}

[numthreads(1, 1, 1)]
void compute_main() {
  textureStore_bcc97a();
  return;
}

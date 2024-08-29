Texture2D arg_0 : register(t0, space1);
SamplerState arg_1 : register(s1, space1);

float textureSample_38bbb9() {
  float res = arg_0.Sample(arg_1, (1.0f).xx).x;
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store(0u, asuint(textureSample_38bbb9()));
  return;
}

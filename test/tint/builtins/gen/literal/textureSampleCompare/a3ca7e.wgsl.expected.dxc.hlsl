TextureCubeArray arg_0 : register(t0, space1);
SamplerComparisonState arg_1 : register(s1, space1);

float textureSampleCompare_a3ca7e() {
  float res = arg_0.SampleCmp(arg_1, float4((1.0f).xxx, float(1)), 1.0f);
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store(0u, asuint(textureSampleCompare_a3ca7e()));
  return;
}

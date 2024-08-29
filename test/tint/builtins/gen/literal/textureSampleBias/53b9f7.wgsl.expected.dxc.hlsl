TextureCube<float4> arg_0 : register(t0, space1);
SamplerState arg_1 : register(s1, space1);

float4 textureSampleBias_53b9f7() {
  float4 res = arg_0.SampleBias(arg_1, (1.0f).xxx, 1.0f);
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store4(0u, asuint(textureSampleBias_53b9f7()));
  return;
}

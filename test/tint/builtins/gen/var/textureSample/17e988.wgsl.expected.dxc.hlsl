Texture2DArray<float4> arg_0 : register(t0, space1);
SamplerState arg_1 : register(s1, space1);

float4 textureSample_17e988() {
  float2 arg_2 = (1.0f).xx;
  int arg_3 = 1;
  float4 res = arg_0.Sample(arg_1, float3(arg_2, float(arg_3)), int2((1).xx));
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store4(0u, asuint(textureSample_17e988()));
  return;
}

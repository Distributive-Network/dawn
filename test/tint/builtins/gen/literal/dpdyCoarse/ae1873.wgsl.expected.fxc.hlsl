float3 dpdyCoarse_ae1873() {
  float3 res = ddy_coarse((1.0f).xxx);
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store3(0u, asuint(dpdyCoarse_ae1873()));
  return;
}

float2 fwidth_b83ebb() {
  float2 res = fwidth((1.0f).xx);
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store2(0u, asuint(fwidth_b83ebb()));
  return;
}

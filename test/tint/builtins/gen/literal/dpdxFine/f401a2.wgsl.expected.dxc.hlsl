float dpdxFine_f401a2() {
  float res = ddx_fine(1.0f);
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

void fragment_main() {
  prevent_dce.Store(0u, asuint(dpdxFine_f401a2()));
  return;
}

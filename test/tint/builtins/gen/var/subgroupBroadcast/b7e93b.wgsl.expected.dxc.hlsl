float4 subgroupBroadcast_b7e93b() {
  float4 arg_0 = (1.0f).xxxx;
  float4 res = WaveReadLaneAt(arg_0, 1u);
  return res;
}

RWByteAddressBuffer prevent_dce : register(u0);

[numthreads(1, 1, 1)]
void compute_main() {
  prevent_dce.Store4(0u, asuint(subgroupBroadcast_b7e93b()));
  return;
}

SKIP: FAILED

vector<float16_t, 4> subgroupBroadcast_0f44e2() {
  vector<float16_t, 4> res = WaveReadLaneAt((float16_t(1.0h)).xxxx, 1u);
  return res;
}

[numthreads(1, 1, 1)]
void compute_main() {
  prevent_dce = subgroupBroadcast_0f44e2();
}

DXC validation failure:
hlsl.hlsl:8:3: error: use of undeclared identifier 'prevent_dce'
  prevent_dce = subgroupBroadcast_0f44e2();
  ^


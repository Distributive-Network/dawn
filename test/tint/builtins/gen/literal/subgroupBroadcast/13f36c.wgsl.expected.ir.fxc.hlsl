SKIP: FAILED

vector<float16_t, 2> subgroupBroadcast_13f36c() {
  vector<float16_t, 2> res = WaveReadLaneAt((float16_t(1.0h)).xx, 1u);
  return res;
}

[numthreads(1, 1, 1)]
void compute_main() {
  prevent_dce = subgroupBroadcast_13f36c();
}


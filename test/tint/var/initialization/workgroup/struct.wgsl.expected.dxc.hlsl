struct S {
  int a;
  float b;
};

groupshared S v;

void tint_zero_workgroup_memory(uint local_idx) {
  if ((local_idx < 1u)) {
    S tint_symbol_2 = (S)0;
    v = tint_symbol_2;
  }
  GroupMemoryBarrierWithGroupSync();
}

struct tint_symbol_1 {
  uint local_invocation_index : SV_GroupIndex;
};

void main_inner(uint local_invocation_index) {
  tint_zero_workgroup_memory(local_invocation_index);
}

[numthreads(1, 1, 1)]
void main(tint_symbol_1 tint_symbol) {
  main_inner(tint_symbol.local_invocation_index);
  return;
}

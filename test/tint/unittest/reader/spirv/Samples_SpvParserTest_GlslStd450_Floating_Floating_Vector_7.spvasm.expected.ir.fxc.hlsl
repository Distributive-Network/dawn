SKIP: FAILED

void main_1() {
  uint u1 = 10u;
  uint u2 = 15u;
  uint u3 = 20u;
  int i1 = 30;
  int i2 = 35;
  int i3 = 40;
  float f1 = 50.0f;
  float f2 = 60.0f;
  float f3 = 70.0f;
  uint2 v2u1 = uint2(10u, 20u);
  uint2 v2u2 = uint2(20u, 10u);
  uint2 v2u3 = (15u).xx;
  int2 v2i1 = int2(30, 40);
  int2 v2i2 = int2(40, 30);
  int2 v2i3 = (35).xx;
  float2 v2f2 = float2(60.0f, 50.0f);
  float2 v2f3 = (70.0f).xx;
  float3 v3f1 = float3(50.0f, 60.0f, 70.0f);
  float3 v3f2 = float3(60.0f, 70.0f, 50.0f);
  float4 v4f1 = (50.0f).xxxx;
  float4 v4f2 = v4f1;
  float2 x_1 = float2(1125899906842624.0f, 1152921504606846976.0f);
}

[numthreads(1, 1, 1)]
void main() {
  main_1();
}


SKIP: FAILED

struct VertexOutput {
  float4 pos;
  float prevent_dce;
};

struct vertex_main_outputs {
  nointerpolation float VertexOutput_prevent_dce : TEXCOORD0;
  float4 VertexOutput_pos : SV_Position;
};


RWByteAddressBuffer prevent_dce : register(u0);
Texture2DArray arg_0 : register(t0, space1);
SamplerState arg_1 : register(s1, space1);
float textureSampleLevel_36780e() {
  float2 arg_2 = (1.0f).xx;
  int arg_3 = 1;
  int arg_4 = 1;
  Texture2DArray v = arg_0;
  SamplerState v_1 = arg_1;
  float2 v_2 = arg_2;
  int v_3 = arg_4;
  float3 v_4 = float3(v_2, float(arg_3));
  float res = v.SampleLevel(v_1, v_4, float(v_3), (1).xx);
  return res;
}

void fragment_main() {
  prevent_dce.Store(0u, asuint(textureSampleLevel_36780e()));
}

[numthreads(1, 1, 1)]
void compute_main() {
  prevent_dce.Store(0u, asuint(textureSampleLevel_36780e()));
}

VertexOutput vertex_main_inner() {
  VertexOutput tint_symbol = (VertexOutput)0;
  tint_symbol.pos = (0.0f).xxxx;
  tint_symbol.prevent_dce = textureSampleLevel_36780e();
  VertexOutput v_5 = tint_symbol;
  return v_5;
}

vertex_main_outputs vertex_main() {
  VertexOutput v_6 = vertex_main_inner();
  VertexOutput v_7 = v_6;
  VertexOutput v_8 = v_6;
  vertex_main_outputs v_9 = {v_8.prevent_dce, v_7.pos};
  return v_9;
}


tint executable returned error: exit status 0xe0000001

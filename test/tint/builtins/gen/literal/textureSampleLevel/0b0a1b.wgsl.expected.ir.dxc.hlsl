SKIP: FAILED

struct VertexOutput {
  float4 pos;
  float4 prevent_dce;
};

struct vertex_main_outputs {
  nointerpolation float4 VertexOutput_prevent_dce : TEXCOORD0;
  float4 VertexOutput_pos : SV_Position;
};


RWByteAddressBuffer prevent_dce : register(u0);
Texture2D<float4> arg_0 : register(t0, space1);
SamplerState arg_1 : register(s1, space1);
float4 textureSampleLevel_0b0a1b() {
  Texture2D<float4> v = arg_0;
  SamplerState v_1 = arg_1;
  float4 res = v.SampleLevel(v_1, (1.0f).xx, float(1.0f), (1).xx);
  return res;
}

void fragment_main() {
  prevent_dce.Store4(0u, asuint(textureSampleLevel_0b0a1b()));
}

[numthreads(1, 1, 1)]
void compute_main() {
  prevent_dce.Store4(0u, asuint(textureSampleLevel_0b0a1b()));
}

VertexOutput vertex_main_inner() {
  VertexOutput tint_symbol = (VertexOutput)0;
  tint_symbol.pos = (0.0f).xxxx;
  tint_symbol.prevent_dce = textureSampleLevel_0b0a1b();
  VertexOutput v_2 = tint_symbol;
  return v_2;
}

vertex_main_outputs vertex_main() {
  VertexOutput v_3 = vertex_main_inner();
  VertexOutput v_4 = v_3;
  VertexOutput v_5 = v_3;
  vertex_main_outputs v_6 = {v_5.prevent_dce, v_4.pos};
  return v_6;
}


tint executable returned error: exit status 0xe0000001

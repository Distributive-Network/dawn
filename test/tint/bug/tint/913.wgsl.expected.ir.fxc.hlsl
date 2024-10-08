struct main_inputs {
  uint3 GlobalInvocationID : SV_DispatchThreadID;
};


Texture2D<float4> src : register(t0);
Texture2D<float4> tint_symbol : register(t1);
RWByteAddressBuffer output : register(u2);
cbuffer cbuffer_uniforms : register(b3) {
  uint4 uniforms[2];
};
bool aboutEqual(float value, float expect) {
  return (abs((value - expect)) < 0.00100000004749745131f);
}

void main_inner(uint3 GlobalInvocationID) {
  uint2 v = (0u).xx;
  src.GetDimensions(v[0u], v[1u]);
  uint2 srcSize = v;
  uint2 v_1 = (0u).xx;
  tint_symbol.GetDimensions(v_1[0u], v_1[1u]);
  uint2 dstSize = v_1;
  uint2 dstTexCoord = uint2(GlobalInvocationID.xy);
  float4 nonCoveredColor = float4(0.0f, 1.0f, 0.0f, 1.0f);
  bool success = true;
  bool v_2 = false;
  if ((dstTexCoord[0u] < uniforms[1u].x)) {
    v_2 = true;
  } else {
    v_2 = (dstTexCoord[1u] < uniforms[1u].y);
  }
  bool v_3 = false;
  if (v_2) {
    v_3 = true;
  } else {
    v_3 = (dstTexCoord[0u] >= (uniforms[1u].x + uniforms[1u].z));
  }
  bool v_4 = false;
  if (v_3) {
    v_4 = true;
  } else {
    v_4 = (dstTexCoord[1u] >= (uniforms[1u].y + uniforms[1u].w));
  }
  if (v_4) {
    bool v_5 = false;
    if (success) {
      Texture2D<float4> v_6 = tint_symbol;
      int2 v_7 = int2(int2(dstTexCoord));
      v_5 = all((float4(v_6.Load(int3(v_7, int(0)))) == nonCoveredColor));
    } else {
      v_5 = false;
    }
    success = v_5;
  } else {
    uint2 srcTexCoord = ((dstTexCoord - uniforms[1u].xy) + uniforms[0u].zw);
    if ((uniforms[0u].x == 1u)) {
      srcTexCoord[1u] = ((srcSize[1u] - srcTexCoord.y) - 1u);
    }
    Texture2D<float4> v_8 = src;
    int2 v_9 = int2(int2(srcTexCoord));
    float4 srcColor = float4(v_8.Load(int3(v_9, int(0))));
    Texture2D<float4> v_10 = tint_symbol;
    int2 v_11 = int2(int2(dstTexCoord));
    float4 dstColor = float4(v_10.Load(int3(v_11, int(0))));
    if ((uniforms[0u].y == 2u)) {
      bool v_12 = false;
      if (success) {
        v_12 = aboutEqual(dstColor[0u], srcColor[0u]);
      } else {
        v_12 = false;
      }
      bool v_13 = false;
      if (v_12) {
        v_13 = aboutEqual(dstColor[1u], srcColor[1u]);
      } else {
        v_13 = false;
      }
      success = v_13;
    } else {
      bool v_14 = false;
      if (success) {
        v_14 = aboutEqual(dstColor[0u], srcColor[0u]);
      } else {
        v_14 = false;
      }
      bool v_15 = false;
      if (v_14) {
        v_15 = aboutEqual(dstColor[1u], srcColor[1u]);
      } else {
        v_15 = false;
      }
      bool v_16 = false;
      if (v_15) {
        v_16 = aboutEqual(dstColor[2u], srcColor[2u]);
      } else {
        v_16 = false;
      }
      bool v_17 = false;
      if (v_16) {
        v_17 = aboutEqual(dstColor[3u], srcColor[3u]);
      } else {
        v_17 = false;
      }
      success = v_17;
    }
  }
  uint outputIndex = ((GlobalInvocationID[1u] * dstSize[0u]) + GlobalInvocationID[0u]);
  if (success) {
    output.Store((0u + (uint(outputIndex) * 4u)), 1u);
  } else {
    output.Store((0u + (uint(outputIndex) * 4u)), 0u);
  }
}

[numthreads(1, 1, 1)]
void main(main_inputs inputs) {
  main_inner(inputs.GlobalInvocationID);
}


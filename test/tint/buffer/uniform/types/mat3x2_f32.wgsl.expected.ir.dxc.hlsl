SKIP: FAILED

[numthreads(1, 1, 1)]
void main() {
  float3x2 x = u;
  s = x;
}

DXC validation failure:
hlsl.hlsl:3:16: error: use of undeclared identifier 'u'
  float3x2 x = u;
               ^
hlsl.hlsl:4:3: error: use of undeclared identifier 's'
  s = x;
  ^


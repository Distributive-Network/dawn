SKIP: FAILED

[numthreads(1, 1, 1)]
void f() {
  int A = 1;
  int _A = 2;
  int B = A;
  int _B = _A;
  s = (((A + _A) + B) + _B);
}

DXC validation failure:
hlsl.hlsl:7:3: error: use of undeclared identifier 's'
  s = (((A + _A) + B) + _B);
  ^


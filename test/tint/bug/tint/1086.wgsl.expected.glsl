#version 310 es
precision highp float;
precision highp int;

float v = 0.0f;
void x(inout float p) {
  p = 0.0f;
}

void g() {
  x(v);
}

void f() {
  g();
}

void main() {
  f();
  return;
}

#version 310 es


struct S {
  int i;
};

void main_1() {
  S V = S(0);
  V.i = 5;
}
layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  main_1();
}

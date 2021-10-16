#include <stdio.h>
void foo(int* x) {
  int i = 3;
  *x = 10;
  x = &i;
}

int main() {
  int i = 5;
  foo(&i);
  printf("i = %d", i);
  return 0;
}
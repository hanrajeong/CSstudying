#include <stdio.h>

union op {
  char c;
  int a;
  int b[3];
};

int main(void) {
  union op var;
  var.a = 65;
  printf("var.a = %d\n", var.a);
  printf("var.b[0] = %d\n", var.b[0]);
  printf("var.c = %c\n", var.c);

  printf("\n---------\n");

  var.b[0] = 66;
  printf("var.a = %d\n", var.a);
  printf("var.b[0] = %d\n", var.b[0]);
  printf("var.b[1] = %d\n", var.b[1]);
  printf("var.c = %c\n", var.c);
  printf("\n---------\n");

  *(&(var.a) + 1) = 100;
  printf("var.a = %d\n", var.a);
  printf("var.b[0] = %d\n", var.b[0]);
  printf("var.b[1] = %d\n", var.b[1]);
  printf("var.c = %c\n", var.c);

  return 0;
}
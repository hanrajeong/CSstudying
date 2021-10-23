#include <stdio.h>

// int foo(int *x, int *y, int z)
// {
//   y = x;
//   z = 7;
//   *y = z;
// }

int main(void)
{
  int a = 0, b= 1, c = 2;
  int z;
  int *x, *y;

  // foo(&a, &b, c);
  // printf("%d %d %d", a, b, c);

  x = &a;
  y = &b;
  z = c;
  x = y;

  printf("%d %d %d\n", a, b, c);
  printf("%d %d %d\n", *x, *y, z);

  return 0;
}
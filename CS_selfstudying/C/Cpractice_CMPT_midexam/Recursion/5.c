#include <stdio.h>

void foo(int n) {
  if (n == 0)
    printf("*");
  else{
    foo(n-1);
    foo(n-1);
  }
}

void foo1(int n) {
  int r = 1;
  for (int i = 0; i < n; i++)
  {
    r *= 2;
  }
  for (int j = 0; j < r; j++)
  {
    printf("*");
  }
}

int main(void)
{
  foo(5);
  printf("\n");
  foo1(5);
}
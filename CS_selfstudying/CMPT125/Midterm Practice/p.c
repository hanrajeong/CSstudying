#include <stdio.h>

int foo(int n)
{
  if (n <= 0)
  {
    return 0;
  }
  return n+2+foo(foo(n-2));
}

int main(void)
{
  printf("%d", foo(3));
}
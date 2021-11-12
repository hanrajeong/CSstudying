#include <stdio.h>

int foo1(int n)
{
  if(n<=1)
    return n*2;
  int half = n/2;
  int n1 = foo1(half);
  int n2 = foo1(n-half);
  return (n1+n2);
}

int foo2(int n)
{
  return 2*n;
}

int main(void)
{
  printf("%d %d", foo1(10), foo2(10));
}
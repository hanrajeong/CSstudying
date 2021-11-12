#include <stdio.h>
#include <math.h>

long foo(int n)
{
  if(n==0) return 1;
  else return foo(n-1) + foo(n-1);
}

long foo2(int n)
{
  return pow(2, n);
}

long foo3(int n)
{
  int ret = 1;
  for(int i = 0; i < n; i++)
  {
    ret *= 2;
  }
  return ret;
}

int main(void)
{
  printf("%d \n", foo(10));
  printf("%d \n", foo2(10));
  printf("%d \n", foo3(10));
}
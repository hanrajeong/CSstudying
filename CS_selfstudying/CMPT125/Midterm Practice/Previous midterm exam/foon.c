#include <stdio.h>
#include <math.h>

int foo(int n)
{
  int sum = 0;
  for(int i = 1; i <n; i=i*2)
  {
    sum = sum+i;
  }
  return sum;
}

int foo1(int n)
{
  int m = (int)floor(log2(n));

  int sum = pow(2, m+1) -1;
  return sum;
}

int main(void)
{
  printf("foo = %d\n", foo(10));
  printf("foo1 = %d", foo1(10));
}
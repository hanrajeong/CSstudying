#include <stdio.h>
#include <math.h>

int foo(int n)
{
  int sum = 0;
  for(int i = 1; i < n; i++)
  {
    for(int j = 1; j <i; j++)
    {
      sum = sum+1;
    }
  }
  return sum;
}

int foo1(int n)
{
  int sum = (n-1)*(n-2)/2;
  return sum;
}

int main(void)
{
  printf("foo = %d\n", foo(10));
  printf("foo1 = %d", foo1(10));
}
#include <stdio.h>

void foo(int n)
{
  if(n==0)
    printf("*");
  else
  {
    foo(n-1);
    foo(n-1);
  }
}

void foo2(int n)
{
  int ret = 1;
  for(int i = 0; i < n; i++)
  {
    ret *= 2;
  }
  for(int i = 0; i < ret; i++)
  {
    printf("*");
  }
}

int main(void)
{
  foo(3);
  printf("\n");
  foo2(3);
}
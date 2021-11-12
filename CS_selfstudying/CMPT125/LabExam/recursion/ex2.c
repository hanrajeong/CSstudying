#include <stdio.h>

void foo(int n)
{
  if(n>0)
  {
    foo(n-1);
    printf("%d ",n);
  }
}

void foo2(int n)
{
  for(int i = 1; i<n+1; i++)
  {
    printf("%d ", i);
  }
}

int main(void)
{
  foo(10);
  printf("\n");
  foo2(10);
}
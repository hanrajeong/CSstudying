#include <stdio.h>

void foo(int n)
{
  if(n>0)
  {
    printf("%d ", n);
    foo(n-1);
  }
}

void foo2(int n)
{
  for(int i=0; i<n; i++)
  {
    printf("%d ", n-i);
  }
}

int main(void)
{
  foo(10);
  printf("\n");
  foo2(10);
}
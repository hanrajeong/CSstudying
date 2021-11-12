#include <stdio.h>

int foo(int n)
{
  if(n==0)
    printf("0 ");
  else
  {
    printf("%d ", n);
    foo(n-1);
    printf("%d ", n);
  }
}

int foo2(int n)
{
  for(int i=n; i>=0; i--)
    printf("%d ", i);
  for(int i=1; i<n+1; i++)
    printf("%d ", i);
}

int main(void)
{
  foo(10);
  printf("\n");
  foo2(10);
}
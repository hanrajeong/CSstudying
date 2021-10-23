#include <stdio.h>

int f1 (int n)
{
  int sum = 0, i;
  for (i = 0; i<n; i++)
  {
    sum+=i;
  }
  return sum;
}

int main(void)c
{
  printf("%d", f1(10));
}
#include <stdio.h>

int bar(int n)
{
  int sum = n*(n+1)/2;

  return sum;
}

int main(void)
{
  int n = 10;
  printf("%d", bar(n));
}
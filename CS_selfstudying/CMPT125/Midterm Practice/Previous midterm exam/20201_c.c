#include <stdio.h>
#include <math.h>

int bar(int n)
{
  return (int)ceil(sqrt(n));
}

int main(void)
{
  printf("%d", bar(0));
}
#include <stdio.h>

int foun(int n);
int main(void)
{
  int a = 100;
  int result = 0;
  result += foun(a);

  printf("a : %d\n", a);
  printf("result : %d\n", result);

  return 0;
}

int foun(int n)
{
  n = 200;
  return n;
}
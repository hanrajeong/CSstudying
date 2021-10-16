#include <stdio.h>

int Add(int num1, int num2);

int main(void)
{
  int a = 10;
  int b = 20;
  int sum = 0;

  sum = Add(a, b);
  printf("%d + %d = %d\n", a, b, sum);

  return 0;
}

int Add(int num1, int num2)
{
  int result = 0;

  result = num1 + num2;

  return result;
}
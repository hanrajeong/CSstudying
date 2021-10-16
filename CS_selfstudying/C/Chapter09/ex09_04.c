#include <stdio.h>

int Add(int a, int b);

int main(void)
{
  int num1;
  int num2;

  printf("Please type two integers: ");
  scanf("%d %d", &num1, &num2);

  int total = Add(num1, num2);

  printf("The sum: %d\n", total);
  return 0;
}

int Add(int a, int b)
{
  int sum = 0;
  sum = a + b;

  return sum;
}
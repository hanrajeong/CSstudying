#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  system("title getting two int, and then get the sum of them");

  int num1, num2, sum_result;

  printf("1st int: ");
  scanf("%d", &num1);
  printf("2nd int: ");
  scanf("%d", &num2);

  sum_result = num1 + num2;
  printf("The result of sum of two given integers: %d + %d = %d", num1, num2, sum_result);
  return 0;
}
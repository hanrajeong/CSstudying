#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  system("title two input of integers and get the difference of them");

  int num1, num2, result;

  printf("Please type two integers in order: ");
  scanf("%d %d", &num1, &num2);

  result = num1 - num2;

  printf("The result of the difference: %d - %d = %d", num1, num2, result);
  return 0;
}
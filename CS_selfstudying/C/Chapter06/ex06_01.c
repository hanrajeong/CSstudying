#include <stdio.h>

int main(void)
{
  int input_num;

  printf("please enter the integer: ");
  scanf("%d", &input_num);

  if (input_num > 0)
  {
    printf("Input number is positive number\n");
    printf("condition is true\n");
  }

  return 0;
}
#include <stdio.h>


int main(void)
{
  int num1, num2;
  float result;

  printf("Enter two integers\n");
  scanf("%d %d", &num1, &num2);

  result = num1/(float)num2;
  printf("%f\n", result);

  return 0;
}
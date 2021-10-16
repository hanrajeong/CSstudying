#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num1, num2, triple;
  float division;

  printf("please type two integers: ");
  scanf("%d %d", &num1, &num2);

  triple = num1 * num1 * num1;
  division = (float)num1/num2;

  printf("Triple: %d * %d * %d = %08d\n", num1, num1, num1, triple);
  printf("Division: %d / %d = %08.3f", num1, num2, division);
}
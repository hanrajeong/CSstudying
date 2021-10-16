#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float a;

  printf("Please type the float with the 6 digits under decimal point: ");
  scanf("%f", &a);

  printf("Print with 2 decimal points: %.2f\n", a);
  printf("Total 6 digits, 1 deimal point: %6.1f\n", a);

  return 0;
}
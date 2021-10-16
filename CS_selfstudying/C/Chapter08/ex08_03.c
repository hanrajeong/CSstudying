#include <stdio.h>
#include <math.h>

int main(void)
{
  int a, b;

  printf("please type two integers: ");
  scanf("%d %d", &a, &b);

  if(a<b)
  {
    double result = pow(a, 3) + pow(b, 2);
    printf("a^3 + b^2 = %d", (int)result);
  }
  else
  {
    printf("a^2 + b^3 = %lf", (pow(a, 2) + pow(b, 3)));
  }

  return 0;
}
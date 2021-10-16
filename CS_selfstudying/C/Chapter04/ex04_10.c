#include <stdio.h>

int main(void)
{
  float base, height;
  double area;

  printf("Please enter the base and the height in cm, 2nd decimal point: ");
  scanf("%f %f", &base, &height);

  area = (base*height)/2;

  printf("%f", area);

  return 0;
}
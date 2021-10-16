#include <stdio.h>
#define pi 3.141592

int main(void)
{
  float r, area = 0;

  printf("radius in cm: ");
  scanf("%d", r);

  area = pi * r * r;

  printf("%f", area);

  return 0;
}
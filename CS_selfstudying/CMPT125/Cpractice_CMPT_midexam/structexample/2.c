#include <stdio.h>
#include <stdlib.h>

struct Distance {
   int m;
   float cm;
} d1, d2, result;

int main()
{
  printf("please type the distance 1: ");
  scanf("%d", &d1.m);
  printf("please type the distance 1 in cm: ");
  scanf("%f", &d1.cm);

  printf("please type the distance 1: ");
  scanf("%d", &d2.m);
  printf("please type the distance 1 in cm: ");
  scanf("%f", &d2.cm);

  result.m = d1.m - d2.m;
  result.cm = d1.cm - d2.cm;

  if(result.m < 0)
  {
    printf("d2 is bigger than d1 for %d m ", result.m);
  }
  else
  {
    printf("d1 is bigger than d2 for %d m ", result.m);
  }
}
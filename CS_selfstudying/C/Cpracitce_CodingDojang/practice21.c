#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct co {
  int x;
  int y;
};

int main(void)
{
  struct co p1;
  struct co p2;

  p1.x = 30;
  p1.y = 20;

  p2.x = 60;
  p2.y = 50;

  int delx = p1.x - p2.x;
  int dely = p1.y - p2.y;

  double diagonal = sqrt(delx * delx + dely * dely);
  double diagonal1 = sqrt(pow(delx, 2) + pow(dely, 2));

  printf("%f %f", diagonal, diagonal1);

  return 0;
}
#include <stdio.h>

int main(void)
{
  int point[] = {23, 25, 2, 9, 75, 96, 82, 16, 48, 85, 33, 67, 95, 37};

  printf("Let's print the number of components in the array\n");

  int count = sizeof(point) / sizeof(point[0]);

  printf("The number of components is %d\n", count);

  return 0;
}
#include <stdio.h>

int main(void)
{
  int num1 = 10;
  int* numptr;

  *numptr = 100;
  printf("%p\n", numptr);
  printf("%d\n", *numptr);
  printf("%d", num1);

  return 0;
}
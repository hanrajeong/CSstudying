#include <stdio.h>

int main(void)
{
  int num1 = 10;

  int *numPtr = &num1;

  *numPtr = 4;

  printf("%d %d", num1, *numPtr);

  return 0;
}
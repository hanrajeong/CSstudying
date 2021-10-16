#include <stdio.h>

int main(void)
{
  int num1 = 2;
  num1 = num1++ + ++num1;

  printf("%d", num1);

  return 0;
}
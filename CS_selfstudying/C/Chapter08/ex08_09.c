#include <stdio.h>

int add_five(int *su);

int main(void)
{
  int num = 100;
  int after;

  after = add_five(&num);

  printf("num: %d, after: %d\n", num, after);

  return 0;
}

int add_five(int *su)
{
  *su += 5;

  return *su;
}
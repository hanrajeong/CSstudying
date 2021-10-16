#include <stdio.h>

float add(int su1, int su2);

int main(void)
{
  int result;
  result = add (3, 8);
  printf("result = %d\n", result);
  return 0;
}

float add(int su1, int su2)
{
  return su1 + su2;
}
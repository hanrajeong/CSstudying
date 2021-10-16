#include <stdio.h>

int f(int a);
int main(void)
{
  int result;
  result = f(5);

  printf("result = %d\n", result);

  return 0;
}

int f(int a)
{
  printf("%02d ", a);
  if (a<1)
  {
    return 3;
  }
  else
  {
    return (3 * f(a - 3) + 1);
  }
}
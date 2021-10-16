#include <stdio.h>

int sum(int a);

int main(void)
{
  int result;
  result = sum(5);
  printf("result = %d\n", result);
  return 0;
}

int sum(int a)
{
  printf("%02d ", a);
  if(a<1)
    return 1;
  else
    return(a+sum(a-2));
}
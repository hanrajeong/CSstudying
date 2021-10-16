#include <stdio.h>

int main(void)
{
  int num = 0;
  int sum = 0;

  do
  { 
    if((sum+num) > 2500)
    {
      break;
    }
    else
    {
      sum += num;
    }
    num++;
  } while (num <= 100);

  printf("For the sum between 1 to %d: %d", num, sum);

  return 0;
}
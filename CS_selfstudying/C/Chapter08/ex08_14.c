#include <stdio.h>

int Sum(int max);

int main(void)
{
  int max = 0;

  printf("please type the maximum number you want to add up to: ");
  scanf("%d", &max);

  int result = Sum(max);

  printf("%d\n", result);

  return 0;
}

int Sum(int max)
{
  int result = 0;

  for(int i = 1; i <= max; i++)
  {
    result += i;
  }

  return result;

}
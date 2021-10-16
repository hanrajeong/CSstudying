#include <stdio.h>

int main(void)
{
  int n = 0;

  retry:
  printf("Please enter the number: ");
  scanf("%d", &n);

  if(n < 0)
  {
    printf("Please enter the positive number!");
    goto retry;
  }

  else
  {
    int i = 1;
    int sum = 0;

    for(; i <= n; i++)
    {
      sum = sum + i;
    }

    printf("The total is %d.", sum);
  }

  return 0;
}
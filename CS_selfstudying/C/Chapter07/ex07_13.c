#include <stdio.h>

int main(void)
{
  int n = 0;

  retry:
  printf("please enter the number: ");
  scanf("%d", &n);

  if(n < 0)
  {
    printf("please type the positive number!");
    goto retry;
  }

  else
  {
    int sum = 0;
    int i = 1;

    while(i<=n)
    {
      sum += i;
      i++;
    }

    printf("The result is %d", sum);
  }
}
// 2~9단까지 출력

#include <stdio.h>

int main(void)
{
  for(int n = 2; n < 10; n++)
  {
    for(int i = 2; i < 10; i++)
    {
      printf("%d x %d = %d\n", n, i, n*i);
    }
  }
  return 0;
}
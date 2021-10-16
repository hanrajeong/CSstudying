#include <stdio.h>

// 재귀함수를 활용한 factorial 함수 정의

long factorial(int su);

int main(void)
{
  int num = 0;

  printf("please type the number you want to get the factorial of: ");
  scanf("%d", &num);

  long result = factorial(num);

  printf("%d! = %d", num, result);

  return 0;
}

long factorial(int su)
{
  if(su <= 1)
  {
    return 1;
  }
  else
  {
    return(su * factorial(su-1));
  }
}
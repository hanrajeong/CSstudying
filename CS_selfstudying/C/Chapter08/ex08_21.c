#include <stdio.h>

// 재귀함수를 사용하여 입력받은 수까지의 sum 출력

int Sum(int n);

int main(void)
{
  int num = 0;
  int result = 0;

  printf("plese type the integer: ");
  scanf("%d", &num);

  result = Sum(num);

  printf("%d\n", result);

  return 0;
}

int Sum(int n)
{
  if(n==1)
  {
    return 1;
  }
  else
  {
    return(n + Sum(n-1));
  }
}
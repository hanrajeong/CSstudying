//2~99단까지 원하는 구구단을 받아서 출력하기
//만약 해당 범위의 값이 아닌 경우 잘못입력했다는 메시지 출력하기

#include <stdio.h>

int main(void)
{
  int n;

  replay:
  printf("Please enter the number between 2-99, that you want to know the multiplication: ");
  scanf("%d", &n);

  if(n >= 100 || n <= 2)
  {
    printf("You typed the incorrect value\n");
    goto replay;
  }

  else
  {
    for(int i = 1; i < 10; i++)
    {
      printf("%d x %d = %d\n", n, i, n*i);
    }
  }
  printf("Here is the multiplication of %d\n", n);

  return 0;
}
/*
1에서 100까지 출력
3의 배수는 Fizz 출력
5의 배수는 Buzz 출력
3과 5의 공배수는 FizzBuzz 출력 */

#include <stdio.h>

int main(void)
{
  int num1, num2;
  scanf("%d %d", &num1, &num2);

  int i = num1;


  while (i<=num2)
  {
    if(i%5 == 0 && i%11==0)
    {
      printf("FizzBuzz\n");
    }
    else if(i%11 == 0)
    {
      printf("Buzz\n");
    }
    else if(i%5 == 0)
    {
      printf("Fizz\n");
    }
    else
    {
      printf("%d\n", i);
    }
    i++;
  }
  return 0;
}
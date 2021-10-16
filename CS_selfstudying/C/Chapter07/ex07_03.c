//1부터 10까지 변수의 합을 출력하는 문제
//출력 형태는 Print the sum(10): 55
//Result = 1 + 2+ 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55

#include <stdio.h>

int main(void)
{
  int num = 1;
  int sum = 0;

  for(; num <= 10; num++)
  {
    sum = sum + num;
    printf("Print the sum(%02d): %02d\n", num, sum);
  }
  printf("1 + 2+ 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = %02d\n", sum);
  return 0;
}
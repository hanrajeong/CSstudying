// count와 sum을 선언해서, 1부터 n까지 누적 합계 : sum, 을 반복 출력, n은 10까지

#include <stdio.h>

int main(void)
{
  int sum = 0;
  
  for(int n = 1; n <= 10; n++)
  {
    sum += n;
    printf("The sum of 1 to %02d : %02d\n", n, sum);
  }
  return 0;
}
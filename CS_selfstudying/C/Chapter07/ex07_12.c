// while문으로 한줄에 숫자 5개씩 출력하기

#include <stdio.h>

int main(void)
{
  int i = 0;

  while(i<30)
  {
    i++;
    printf("%02d ", i);

    if(i % 5 == 0)
    {
      printf("\n");
    }
  }
  return 0;
}
#include <stdio.h>

int main(void)
{
  int a = 8;
  int * pa = NULL; //가비지값 발생을 배제하고자 초기화함.

  pa = &a;

  float b = 3.75;
  float *pb = &b;

  printf("adress of a: %d", &a);
  printf("adress of pa: %d", pa);

  printf("adress of b: %d", &b);
  printf("adress of pb: %d", pb);
  printf("adress of NULL: %d", NULL);

  return 0;
}
#include <stdio.h>

int main(void)
{
  //const int * 랑 int * const 차이점 확인 코드

  int x = 6;
  int y = 10;

  const int *ptr = &x;
  // ptr = &y;
  // *ptr = 10;
  x = 50;
  printf("%d", *ptr);

  int* const ptr2 = &x;
  printf("%d", *ptr2);
  x = 15;
  printf("%d", *ptr2);
  // *ptr2 = 500;
  // printf("%d", &ptr2);
}
#include <stdio.h>

int main(void)
{
  int x = 1;
  int y = 2;
  int* ptr1 = &x;
  int* ptr2 = &y;

  *ptr2 = 3;
  ptr2 = ptr1;
  *ptr2 = 4;

  printf("x= %d\n", x);
  printf("y = %d\n", y);
  printf("ptr1 = %d\n", *ptr1);
  printf("ptr2 = %d\n", *ptr2);
}
#include <stdio.h>

int main(void)
{
  int x = 1;
  int* ptr1 = &x;
  int y = 2;
  int* ptr2 = &y;

  *ptr1 = 2;
  ptr2 = ptr1;
  ptr1 = &y;
  *ptr1 = 3;

  printf("x= %d\n", x);
  printf("y = %d\n", y);
  printf("ptr1 = %d\n", *ptr1);
  printf("ptr2 = %d\n", *ptr2);
}
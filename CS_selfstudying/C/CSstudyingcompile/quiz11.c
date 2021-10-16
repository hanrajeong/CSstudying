#include <stdio.h>

int main()
{
  int x = 1;
  int y = 2;
  int* ptr1 = &x;
  int* ptr2 = &y;

  *ptr1 = *ptr2;
  printf("%d, %d\n", x, y);
  *ptr2 = 3;
  printf("%d, %d\n", x, y);
  ptr2 = ptr1;

  printf("%d, %d\n", x, y);
}
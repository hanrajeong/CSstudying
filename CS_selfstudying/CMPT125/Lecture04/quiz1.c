
#include <stdio.h>

int main() {
  int x = 1;
  int y = 2;
  int* ptr1 = &x;
  int* ptr2 = &y;
  *ptr1 = *ptr2;
  *ptr2 = 3;
  ptr2 = ptr1;
  printf("x = %d, y = %d\n", x, y);
  return 0;
}
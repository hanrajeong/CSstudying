#include <stdio.h>

// implement swap of two numbers (using pointers)

int main(void)
{
  int x, y, *a, *b, tmp;

  printf("please enter the value for x: ");
  scanf("%d", &x);
  printf("please enter the value for y: ");
  scanf("%d", &y);

  a = &x;
  b = &y;

  tmp = x;
  *a = *b;
  *b = tmp;

  printf("x : %d, y : %d", x, y);

  return 0;
}
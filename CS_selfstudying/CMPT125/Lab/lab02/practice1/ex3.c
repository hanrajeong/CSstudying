#include <stdio.h>

int main()
{
  int x, y, *a, *b, tmp;
  printf("Enter the value for x:\n");
  scanf("%d", &x);
  printf("Enter the value for y:\n");
  scanf("%d", &y);

  a = &x;
  b = &y;
  tmp = *b;
  *b = *a;
  *a = tmp;

  printf("After x = %d, y = %d", x, y);
}
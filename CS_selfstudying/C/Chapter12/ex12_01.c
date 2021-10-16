#include <stdio.h>

int main(void)
{
  char a[] = "computer";
  char *b = "computer";

  printf("adress of a : %d\n", a);
  printf("adress of b: %d\n", b);
  

  for (int c = 0; c < 8; c++)
  {
    printf("a[%d] = %c     ", c, a[c]);
    printf("*p %d = %c\n", c, *(b+c));
  }
}
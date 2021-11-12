#include <stdio.h>

void change(int* n)
{
  *n=10;
}

int main(void)
{
  int a = 0;
  int* b;
  *b=a;
  printf("%d\n", *b);
  change(b);
  printf("%d", *b);
}
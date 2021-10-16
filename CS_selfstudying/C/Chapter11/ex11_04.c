#include <stdio.h>

int main(void)
{
  int a = 30;
  int *p = NULL;

  p = &a;

  printf("the adress of p: %d\n", p);
  printf("the data of pointer p: %d\n", *p);

  *p = 50;

  printf("the adress of p: %d\n", p);
  printf("the data of pointer p: %d\n", *p);
  printf("the data of a: %d\n", a);

  return 0;
}
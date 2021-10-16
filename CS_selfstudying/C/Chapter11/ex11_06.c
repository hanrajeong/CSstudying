#include <stdio.h>

int main(void)
{
  int a;
  int *pa = NULL;

  pa = &a;
  *pa = 3.5;

  printf("the adress of pointer pa: %d", pa);
  printf("the adress of a: %d", &a);
  printf("the data of pa, %d", *pa);
  printf("the data of a: %d", a);
}
#include <stdio.h>

int main(void)
{
  int a = 300;
  int *pa = &a;

  printf("adress of pointer pa: %d\n", pa);
  printf("adress of a's data: %d\n", &a);
  printf("data of a: %d\n", a);
  printf("data of pointer pa: %d\n", *pa);

  return 0;

}
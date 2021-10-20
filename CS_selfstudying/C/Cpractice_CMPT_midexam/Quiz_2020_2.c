#include <stdio.h>

int main(void)
{
  int ar[4] = {1, 2, 3, 4};
  int* ptr1 = ar+1;
  *(ptr1 + 2) = 5;

  printf("*ptr1 = %d\n", *ptr1);
  printf("ar[2] = %d\n", ar[2]);
  printf("ar[3] = %d\n", ar[3]);
}
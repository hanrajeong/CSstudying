#include <stdio.h>

int main(void)
{
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *ptr;

  ptr = arr + 3;
  printf("*ptr = %d\n", *ptr);

  ptr = ptr + 2;
  printf("*ptr = %d\n", *ptr);

  ptr = &arr[9];
  printf("*ptr = %d\n", *ptr);
}
#include <stdio.h>

int main(void)
{
  int arr[5] = {10, 1, 2, 3, 4};
  int *ptr;

  ptr = arr;

  for(int i = 0; i < 5; i++)
  {
    printf("%p, %d\n", (ptr+i), *(ptr+i));
  }

  return 0;
}
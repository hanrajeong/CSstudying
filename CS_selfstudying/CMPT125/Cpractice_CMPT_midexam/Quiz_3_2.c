#include <stdio.h>

int main(void)
{
  int ar[3] = {10, 20, 30};
  const int* ptr = ar;
  printf("%d\n", *(ptr+1));

  ptr = ptr + 1;

  printf("%d\n", *(ptr+1));
}
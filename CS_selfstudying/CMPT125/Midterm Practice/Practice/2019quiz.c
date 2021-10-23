#include <stdio.h>

int main()
{
  int ar[4] = {10, 20, 30};

  const int* ptr = ar;
  int* ptr2 = ar+2;
  printf("%d ", *(ptr+1));

  *ptr2 = 50;
  ptr = ptr+1;
  printf("%d ", *(ptr+1));

  return 0;
}
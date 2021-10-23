#include <stdio.h>
#include <stdlib.h>

int main()
{
  int* a = (int *)malloc(5* sizeof(int));
  for (int i = 0; i < 5; i++)
  {
    a[i] = i;
  }
  int* b;
  b = a;
  printf("b[2] = %d\n", b[2]);
  return 0;
}


#include <stdio.h>
#include <stdlib.h>

int* reverse_ar(const int* ar, int len)
{
  int* new = (int*)malloc(len*sizeof(int));
  for(int i = 0; i < len; i++)
  {
    new[i] = ar[len-i-1];
  }
  return new;
}

int main(void)
{
  int ar[5] = {1, 2, 3, 4, 5};
  for(int i=0; i<5; i++)
  {
    printf("%d ", ar[i]);
  }
  printf("\n");
  int* new = reverse_ar(ar, 5);
  for(int i=0; i<5; i++)
  {
    printf("%d ", new[i]);
  }
}
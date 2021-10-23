#include <stdio.h>
#include <stdlib.h>

int *reverse_ar(const int *ar, int len)
{
  int *reverse_ar = (int*)malloc(len*sizeof(int));
  for (int i = 0; i < len; i++)
  {
    reverse_ar[i] = ar[len - i - 1];
  }

  return reverse_ar;
}

int main(void)
{
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int *ar = arr;
  int len = 6;

  for(int i = 0; i < len; i++)
  {
    printf("%d", reverse_ar(ar, len)[i]);
  }
}
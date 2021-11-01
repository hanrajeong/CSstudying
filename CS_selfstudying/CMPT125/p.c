#include <stdio.h>

int* max_prefixes(int* ar, int n)
{
  int max = ar[0];
  for(int i = 1; i < n; i++)
  {
    if(ar[i] > max)
    {
      max = ar[i];
    }
    else
    {
      ar[i] = max;
    }
  }
  return ar;
}

int main(void)
{
  int ar[6] = {1, 4, 3, 8, 2, 9};
  int *b = max_prefixes(ar, 6);
  for(int j = 0; j<6; j++)
  {
    printf("%d ", b[j]);
  }
}
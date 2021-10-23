#include <stdio.h>

void printf_max_number(const int digits[], int n)
{
  int max;
  int arr[n];

  for(int p = 0; p < n; p++)
  {
    arr[p] = digits[p];
  }

  for(int i = 0; i < n-2; i++)
  {
    max = i;
    for(int j = i + 1; j < n; j++)
    {
      if(arr[max] < arr[j])
      {
        max = j;
      }
    }
    if(i != max)
    {
      int temp = arr[i];
      arr[i] = arr[max];
      arr[max] = temp;
    }
  }

  for(int k = 0; k < n; k++)
  {
    printf("%d", arr[k]);
  }
}

int main(void)
{
  int arr[9] = {7, 5, 3, 8, 3, 0, 0, 0, 0};
  int n = 9;

  printf_max_number(arr, n);

  return 0;
}
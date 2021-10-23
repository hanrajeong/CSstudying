#include <stdio.h>

void print_max_number(const int digits[], int n)
{
  int max_i;
  int arr[n];
  for(int k = 0; k < n; k++)
  {
    arr[k] = digits[k];
  }

  for(int i = 0; i < n; i++)
  {
    max_i = i;
    for(int j = i+1; j < n; j++)
    {
      if(arr[j] > arr[max_i])
      {
        max_i = j;
      }
    }
    if(max_i != i)
    {
      int temp = arr[i];
      arr[i] = arr[max_i];
      arr[max_i] = temp;
    }
  }

  for(int q = 0; q < n; q++)
  {
    printf("%d", arr[q]);
  }
}

int main(void)
{
  int arr[10] = {1, 2, 4, 4, 4, 6, 7, 8, 9, 0};
  print_max_number(arr, 10);
}
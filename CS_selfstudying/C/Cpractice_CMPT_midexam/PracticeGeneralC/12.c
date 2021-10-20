#include <stdio.h>

int longest_incr_subsequence(const int arr[], int n)
{
  int j = 1;
  int index = 0;
  int num[n];
  for (int q = 0; q < n; q++)
  {
    num[q] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    if(arr[i] > arr[i+1])
    {
      index = i+1;
      num[j] = index;
      j++;
    }
  }

  int max = num[1] - num[0];

  for(int k = 0; k < n -1; k++)
  {
    if(max < (num[k+1] - num[k]))
    {
      max = num[k+1] - num[k];
    }
  }
  return max;
}

int main(void)
{
  int arr[10] = {1, 2, 6, 4, 3, 8, 9, 10, 2, 4};

  printf("%d", longest_incr_subsequence(arr, 10));

  return 0;
}
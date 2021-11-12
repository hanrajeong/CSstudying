#include <stdio.h>

int longest_incr_subsequence(const int arr[], int n)
{
  int len = 1;
  int max = 1;
  for(int i = 0; i < n; i++)
  {
    if(arr[i]<arr[i+1])
    {
      len+=1;
    }
    else
    {
      if(max < len)
      {
        max = len;
      }
      len = 1;
    }
  }
  return max;
}

int main(void)
{
  int arr[10] = {1, 2, 6, 4, 3, 8, 9, 10, 2, 4};
  printf("%d", longest_incr_subsequence(arr, 10));
}
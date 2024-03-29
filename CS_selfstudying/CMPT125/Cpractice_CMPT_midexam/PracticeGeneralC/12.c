#include <stdio.h>

// int longest_incr_subsequence(const int arr[], int n)
// {
//   int j = 1;
//   int index = 0;
//   int num[n];
//   for (int q = 0; q < n; q++)
//   {
//     num[q] = 0;
//   }
//   for (int i = 0; i < n; i++)
//   {
//     if(arr[i] > arr[i+1])
//     {
//       index = i+1;
//       num[j] = index;
//       j++;
//     }
//   }

//   int max = num[1] - num[0];

//   for(int k = 0; k < n -1; k++)
//   {
//     if(max < (num[k+1] - num[k]))
//     {
//       max = num[k+1] - num[k];
//     }
//   }
//   return max;
// }

int longest_incr_subsequence(const int arr[], int n)
{
  int count = 1;
  int max = 0;
  for(int i = 0; i<n-1; i++)
  {
    if(arr[i] < arr[i+1])
    {
      count++;
    }
    else 
    { 
      if(count > max)
      {
      max = count;
      count = 1;
      }
      else
      {
        count = 1;
      }
    }
    
  }
  return max;
}

int main(void)
{
  int arr[12] = {1, 2, 6, 4, 3, 8, 9, 0, 11, 12, 14, 0};

  printf("%d", longest_incr_subsequence(arr, 12));

  return 0;
}
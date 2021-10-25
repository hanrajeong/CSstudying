#include <stdio.h>
#include <stdlib.h>

// void printf_max_number(const int digits[], int n)
// {
//   int max;
//   int arr[n];

//   for(int p = 0; p < n; p++)
//   {
//     arr[p] = digits[p];
//   }

//   for(int i = 0; i < n-2; i++)
//   {
//     max = i;
//     for(int j = i + 1; j < n; j++)
//     {
//       if(arr[max] < arr[j])
//       {
//         max = j;
//       }
//     }
//     if(i != max)
//     {
//       int temp = arr[i];
//       arr[i] = arr[max];
//       arr[max] = temp;
//     }
//   }

//   for(int k = 0; k < n; k++)
//   {
//     printf("%d", arr[k]);
//   }
// }

void print_max_number(const int digits[], int n)
{
  int *arr = (int*)malloc(n*sizeof(int));
  for(int i = 0; i < n; i++)
  {
    arr[i] = digits[i];
  }
  int max_idx;
  for(int j = 0; j <n; j++)
  {
    max_idx = j;
    for(int k = j+1; k < n; k++)
    {
      if(arr[k] > arr[max_idx])
      {
        max_idx = k;
      }
    }
    int temp = arr[max_idx];
    arr[max_idx] = arr[j];
    arr[j] = temp;
  }
  for(int p = 0; p <n; p++)
  {
    printf("%d", arr[p]);
  }
}

int main(void)
{
  int arr[9] = {7, 5, 3, 8, 3, 0, 0, 0, 0};
  int n = 9;

  print_max_number(arr, n);

  return 0;
}
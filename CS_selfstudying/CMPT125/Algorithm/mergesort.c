#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end)
{
  int length = end - start + 1;
  int *sorted_arr = malloc(length * sizeof(int));
  int k = 0;
  int i = start;
  int j = mid + 1;

  while(i <= mid && j <=end)
  {
    if(arr[i] <= arr[j])
    {
      sorted_arr[k] = arr[i];
      k++;
      i++;
    }
    else
    {
      sorted_arr[k] = arr[j];
      k++;
      j++;
    }
  }
  while(i<=mid)
  {
    sorted_arr[k] = arr[i];
    i++;
  }
  while(j<=end)
  {
    sorted_arr[k] = arr[j];
    j++;
  }

  for(int p = 0; p < length; p++)
  {
    arr[start+p] = sorted_arr[k];
    k++;
  }
}


void mergesort(int* arr, int start, int end)
{
  if(start < end)
  {
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
  
}



int main(void)
{
  int n = 0;
  printf("please type the length of array you want to sort ");
  scanf("%d", &n);

  int *arr = (int*)malloc(n*sizeof(int));
  printf("please type the array : ");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  for(int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");

  mergesort(arr, 0, n-1);

  for(int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}

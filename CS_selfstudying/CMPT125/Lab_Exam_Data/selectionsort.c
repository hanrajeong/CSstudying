#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* ar, int n)
{
  int min;
  for(int i = 0; i < n; i++)
  {
    min = i;
    for(int j = i+1; j < n; j++)
    {
      if(ar[j]<ar[min])
        min=j;
    }
    int temp = ar[min];
    ar[min] = ar[i];
    ar[i] = temp; 
  }
}

void insertion_sort(int* ar, int n)
{
  int j;
  for(int i = 1; i<n; i++)
  {
    int p = ar[i];
    j=i-1;
    while(j>=0 && ar[j]>p)
    {
      ar[j+1] = ar[j];
      j--;
    }
    ar[j+1] = p;
  }
}

void merge(int* arr, int n, int mid)
{
  int* sorted = (int*)malloc(n*sizeof(int));
  int i = 0;
  int k = 0;
  int j = mid;
  while(i<mid && j<n)
  {
    if(arr[i] < arr[j])
      sorted[k++] = arr[i++];
    else
      sorted[k++] = arr[j++];
  }
  while(i<mid)
    sorted[k++] = arr[i++];
  while(k<n)
    sorted[k++] = arr[j++];
  for(int p = 0; p<n; p++)
    arr[p] = sorted[p];
  free(sorted);
}

void merge_sort(int* ar, int n)
{
  if(n<=1)
    return;
  int mid = n/2;
  merge_sort(ar, mid);
  merge_sort(ar+mid, n-mid);
  merge(ar, n, mid);
}

void quick_sort(int* ar, int n, int pivot_idx)
{
  if(n<=1)
    return;
  int pivot = ar[pivot_idx];
  int temp = ar[0];
  ar[0] = ar[pivot_idx];
  ar[pivot_idx] = temp;
  int left = 1;
  int right = n-1;
  while(left<=right)
  {
    while(ar[left]<pivot)
      left++;
    while(ar[right]>pivot)
      right--;
    if(left<=right)
    {
      temp = ar[left];
      ar[left] = ar[right];
      ar[right] = temp;
    }
  }
  temp = ar[0];
  ar[0] = ar[right];
  ar[right] = temp;
  quick_sort(ar, right, 0);
  quick_sort(ar+right+1, n-right-1, 0);
}

int compare(const void* a, const void* b)
{
  return ( *(int*)a - *(int*)b );
}

void print(int* ar, int n)
{
  for(int i = 0; i < n; i++)
    printf("%d ", ar[i]);
  printf("\n");
}

int main(void)
{
  int ar[10] = {1, 5, 2, 3, 6, 4, 9, 7, 10, 8};
  print(ar, 10);
  qsort(ar, 10, sizeof(int), compare);
  print(ar, 10);

}
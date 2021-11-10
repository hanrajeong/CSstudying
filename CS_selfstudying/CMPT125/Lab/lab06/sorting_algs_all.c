#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int* ar, int n)
{
  int i, j, key;
  for(i=1; i<n; i++)
  {
    j=i-1;
    key=ar[i];
    while(j>=0 && ar[j]>key)
    {
      ar[j+1]=ar[j];
      j--;
    }
    ar[j+1] = key;
  }
}

void selection_sort(int* ar, int n)
{
  int i, j, min, temp;
  for(i=0; i<n; i++)
  {
    min = i;
    for(j=i+1; j<n; j++)
    {
      if(ar[j]<ar[min])
        min = j;
    }
    temp = ar[i];
    ar[i] = ar[min];
    ar[min] = temp;
  }
}

void merge(int* ar, int n, int mid)
{
  int* sorted = (int*)malloc(n*sizeof(int));
  int i = 0;
  int j = mid;
  int k = 0;
  while(i<mid && j<n)
  {
    if(ar[i]<ar[j])
      sorted[k++] = ar[i++];
    else
      sorted[k++] = ar[j++];
  }
  while(i<mid)
    sorted[k++] = ar[i++];
  while(j<n)
    sorted[k++] = ar[j++];
  for(int p = 0; p<n; p++)
    ar[p] = sorted[p];
}

void merge_sort(int* ar, int n)
{
  if(n<2)
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
  temp = ar[right];
  ar[right] = ar[0];
  ar[0] = temp;
  quick_sort(ar, right, 0);
  quick_sort(ar+right+1, n-right-1, 0);
}


void set_rand(int* ar, int n) {
  srand(0);
  int i;
  for(i=0; i<n; i++)
    ar[i] = rand();
}

int main() {
  int LENGTH = 10;
  int ar1[LENGTH];
  int ar2[LENGTH];
  int ar3[LENGTH];
  int ar4[LENGTH];
  int ar5[LENGTH];
  int ar6[LENGTH];
  int ar7[LENGTH];

  // create a random array
  set_rand(ar1, LENGTH);
  // copy ar1 into ar2 and ar3 and ar4
  memcpy(ar2, ar1, LENGTH*sizeof(int));
  memcpy(ar3, ar1, LENGTH*sizeof(int));
  memcpy(ar4, ar1, LENGTH*sizeof(int));
  memcpy(ar5, ar1, LENGTH*sizeof(int));
  // memcpy(ar6, ar1, LENGTH*sizeof(int));
  // memcpy(ar7, ar1, LENGTH*sizeof(int));

  for(int i = 0; i < LENGTH; i++)
  {
    printf("%d ", ar1[i]);
  }
  printf("\n");


  printf("Mergesort\n");
  merge_sort(ar2, LENGTH);
  for(int i = 0; i < LENGTH; i++)
  {
    printf("%d ", ar2[i]);
  }
  printf("\n");

  printf("Quicksort\n");
  quick_sort(ar3, LENGTH, 5);
  for(int i = 0; i < LENGTH; i++)
  {
    printf("%d ", ar3[i]);
  }
  printf("\n");

  printf("Selectionsort\n");
  selection_sort(ar4, LENGTH);
  for(int i = 0; i < LENGTH; i++)
  {
    printf("%d ", ar4[i]);
  }
  printf("\n");  

  printf("Insertionsort\n");
  insertion_sort(ar5, LENGTH);
  for(int i = 0; i < LENGTH; i++)
  {
    printf("%d ", ar5[i]);
  }
  printf("\n");  

  return 0;
}

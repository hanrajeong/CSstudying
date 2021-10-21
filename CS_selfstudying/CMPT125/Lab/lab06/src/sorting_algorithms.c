#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//이전꺼랑 비교하면서 앞으로 삽입하는 유형
void Insertionsort(int* arr, int n)
{
  int key;
  int j;

  for(int i = 1; i < n; i++)
  {
    key = arr[i];
    for(j = i-1; j>=0; j--)
    {
      if(arr[j] > key)
      {
        arr[j+1] = arr[j];
      }
      else
      {
        break;
      }
    }
    arr[j+1] = key; 
  }
}

void Selectionsort(int* arr, int n)
{
  int min_index = 0;
  int i, j;
  int temp;

  for(j=0; j<n-1; j++)
  {
    min_index = j;
    for(i=j+1; i<n; i++)
    {
      if(arr[i] < arr[min_index])
      {
        min_index = i;
      }
    }
    temp = arr[j];
    arr[j] = arr[min_index];
    arr[min_index] = temp;
  }  
}

void merge(int* arr, int n){
  int left = 0;
  int mid = n/2;
  int right = n-1;
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;
  int sorted[1000];

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(arr[i]<=arr[j])
      sorted[k++] = arr[i++];
    else
      sorted[k++] = arr[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = arr[l];
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = arr[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    arr[l] = sorted[l];
  }
}

void mergesort(int* arr, int n)
{
  int mid;

  if(n>0)
  {
    mid = n/2;
    mergesort(arr, mid);
    mergesort(arr+mid, n-mid-1);
    merge(arr, mid);
  }
}

void quicksort(int* arr, int n)
{

  int temp;
  int pivot;
  int left;
  int right;

  if(n>1)
  {
    pivot = 0;
    left = 1;
    right = n-1;
    while(left<right)
    {
      while(arr[left] < arr[pivot])
      {
        left++;
      }
      while(arr[right] > arr[pivot])
      {
        right--;
      }
      temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;
    }
    temp = arr[pivot];
    arr[pivot] = arr[left];
    arr[left] = temp;
    quicksort(arr, left);
    quicksort(arr+left, n-left-1);
  }
}

void set_rand(int* ar, int n) {
  srand(0);
  int i;
  for(i=0; i<n; i++)
    ar[i] = rand();
}

int main(void)
{
  int LENGTH = 10;
  int i;

  int ar1[LENGTH];
  int ar2[LENGTH];
  int ar3[LENGTH];
  int ar4[LENGTH];
  int ar5[LENGTH];

  // create a random array
  set_rand(ar1, LENGTH);
  // copy ar1 into ar2 and ar3 and ar4
  memcpy(ar2, ar1, LENGTH*sizeof(int));
  memcpy(ar3, ar1, LENGTH*sizeof(int));
  memcpy(ar4, ar1, LENGTH*sizeof(int));
  memcpy(ar5, ar1, LENGTH*sizeof(int));

  for(i = 0; i<LENGTH; i++)
  {
    printf("%d ", ar1[i]);
  }
  printf("\n");

  printf("Insertion sort on array of length %d...\n", LENGTH);
  Insertionsort(ar2, LENGTH);
  for(i = 0; i<LENGTH; i++)
  {
    printf("%d ", ar2[i]);
  }
  printf("\n");

  printf("Selection sort on array of length %d...\n", LENGTH);
  Selectionsort(ar3, LENGTH);
  for(i =0; i<LENGTH; i++)
  {
    printf("%d ", ar3[i]);
  }
  printf("\n");

  printf("Merge sort on array of length %d...\n", LENGTH);
  mergesort(ar4, LENGTH);
  for(i = 0; i<LENGTH; i++)
  {
    printf("%d ", ar4[i]);
  }
  printf("\n");

  printf("Quick sort on array of length %d...\n", LENGTH);
  quicksort(ar5, LENGTH);
  for(i = 0; i<LENGTH; i++)
  {
    printf("%d ", ar5[i]);
  }
  printf("\n");
}

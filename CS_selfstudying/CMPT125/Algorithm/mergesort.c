#include <stdio.h>
#include <stdlib.h>

void merge(int* A, int n, int mid)
{
  int *arr = (int*)malloc(n*sizeof(int));
  int i =0;
  int j = mid;
  int k = 0;

  while(i <= mid-1 && j <= n-1)
  {
    if(A[i] < A[j])
    {
      arr[k] = A[i];
      k++;
      i++;
    }
    else
    {
      arr[k] = A[j];
      k++;
      j++;
    }
  }
  while(i<=(mid-1))
  {
    arr[k] = A[i];
    k++;
    i++;
  }
  while(j<=(n-1))
  {
    arr[k] = A[j];
    k++;
    j++;
  }
  for(int p = 0; p < n; p++)
  {
    A[p] =arr[p];
  }
  free(arr);
}
void merge_sort(int* A, int n) 
{
  if (n >= 2) 
  {
    int mid = n/2;
    merge_sort(A, mid);
    merge_sort(A+mid, n-mid);
    merge(A,n,mid);
  }
}

int main(void)
{
  int A[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  for(int i = 0; i <10; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
  printf("\n");
  merge_sort(A, 10);
  for(int i = 0; i <10; i++)
  {
    printf("%d ", A[i]);
  }

}

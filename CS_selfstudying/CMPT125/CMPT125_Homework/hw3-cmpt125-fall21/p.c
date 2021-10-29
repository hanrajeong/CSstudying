#include <stdio.h>

int middle(int* A, int right)
{
  int left = 0;
  int mid = (left + right) / 2;
  right--;
  // printf("\n");
  // printf("%d %d %d", A[left], A[mid], A[right]);
  if ((A[left] <= A[mid]) && (A[mid] <= A[right])) return mid;
  if ((A[left] <= A[right]) && (A[right] <= A[mid])) return right;
  if ((A[mid] <= A[left]) && (A[left] <= A[right])) return left;
  if ((A[mid] <= A[right]) && (A[right] <= A[left])) return right;
  if ((A[right] <= A[left]) && (A[left] <= A[mid])) return left;
  return mid;
}


void quick_sort(int* A, int n) {
  if(n<=1)
  {
    return;
  }
  if(n==2)
  {
    if(A[0] <= A[1])
    {
      return;
    }
    else
    {
      int t = A[0];
      A[0] = A[1];
      A[1] = t;
      return;
    }
  }
  int pivot_idx = middle(A, n);
  int pivot = A[pivot_idx];
  int temp = A[0];
  A[0] = A[pivot_idx];
  A[pivot_idx] = temp;
  int left = 1;
  int right = n-1;
  while(left <= right)
  {
    while(A[left] <= pivot)
    {
      left++;
    }
    while(A[right] >= pivot)
    {
      right--;
    }
    if(left <= right)
    {
      temp=A[left];
      A[left] = A[right];
      A[right] = temp;
    }
  }
  temp = A[right];
  A[right] = A[0];
  A[0] = temp;
  printf("\n");
  quick_sort(A, right);
  quick_sort(A+right+1, n-right-1);
}

int main(void)
{
  int a[] = {4,1,2,7,5,3,2};
  quick_sort(a,7);

  for(int i = 0; i < 7; i++)
  {
    printf("%d", a[i]);
  }
}

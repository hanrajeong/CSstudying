#include <stdio.h>

int findK(int *A, int n)
{
  if(n<=0)
  {
    return -1;
  }
  int mid;
  mid = n/2;
  if(A[mid]<A[mid-1] && A[mid]>A[mid+1])
  {
    findK(A+mid, n-mid);
  }
  else if(A[mid]>A[mid-1]&&A[mid]<A[mid+1])
  {
    findK(A, n-mid);
  }
  else
  {
    return mid;
  }
}

int main(void)
{
  int A[8] = {10, 8, 7, 5, 1, 3, 7, 9};
  printf("%d", findK(A, 8));
}
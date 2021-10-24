#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "assignment3.h"

int rearrange(int* A, int n, int pivot_index) {
  // implement me
  int left = 1;
  int right = n-1;
  int temp;
  temp = A[pivot_index];
  A[pivot_index] = A[0];
  A[0] = A[pivot_index];

  while(left<right)
  {
    while(A[left]>=A[pivot_index])
    {
      left++;
    }
    while(A[right]<=A[pivot_index])
    {
      right--;
    }
    temp = A[left];
    A[left] = A[right];
    A[right] = temp;
  }
  int p = right;
  temp = A[right];
  A[right] = A[0];
  A[0] = A[right];

  rearrange(A, right+1, 0);
  rearrange(A+right, n-right-1, 0);
  return 0;
}


void quick_sort(int* A, int n) {
  // implement me
}


void sort_points(point* A, int length) {
  // implement me
}


int find(int* A, int n, bool (*pred)(int)) {
  // implement me
  return -1;
}


void map(int* A, int n, int (*f)(int)) {
  // implement me
}


int reduce(int* A, int n, int (*f)(int,int)) {
  // implement me
  return -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "assignment3.h"

int rearrange(int* A, int n, int pivot_index) {
  // {4,1,2,7,5,3,2}
  // (4,1,2,2,5,3,7) -- swap (2,7)
  // (4,1,2,2,3,5,7) -- swap (5,3)
  // (3,1,2,2,4,5,7) -- move pivot to the right place
  int pivot = A[pivot_index]; 
  int temp = A[0]; // swap the pivot to the front, index 0 to start sorting
  A[0] = A[pivot_index];
  A[pivot_index] = temp;
  int left = 1; // declare two pointer, left and right
  int right = n-1;
  while(left <= right)
  {
    while(A[left] <= pivot)
    {
      left++;
    }
    while(A[right] > pivot)
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

  return right;
}

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
  quick_sort(A, right);
  quick_sort(A+right+1, n-right-1);
}

int compare(const void* first, const void* second)
{
  point* one = (point*)first;
	point* two = (point*)second;

  int x1 = one->x;
  int y1 = one->y;
  int x2 = two->x;
  int y2 = two->y;
	if (x1*x1 + y1*y1 < x2*x2 + y2*y2)
		return -1;
	else if (x1*x1 + y1*y1 > x2*x2 + y2*y2)
		return 1;
	else
	{
		if (x1 < x2)
			return -1;
		else
			return 1;
	}
	return 0;
}


void sort_points(point* A, int length) {
  //   point A[6] = {{3,2}, {7,1}, {1,1}, {3,4}, {5,0}, {7,1}};
  qsort(A, length, sizeof(A[0]), compare);
}

int find(int* A, int n, bool (*pred)(int)) {
  // implement me
  for(int i = 0; i < n; i++)
  {
    if(pred(A[i]) != 0)
    {
      return i;
    }
  }
  return -1;
}


void map(int* A, int n, int (*f)(int)) {
  // implement me
  for(int i = 0; i < n; i++)
  {
    A[i] = f(A[i]);
  }
}


int reduce(int* A, int n, int (*f)(int,int)) {
  // implement me
  int result = f(A[0], A[1]);
  for(int i = 2; i < n; i++)
  {
    result = f(result, A[i]);
  }
  return result;
}

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
  while(left <= right) // start quick sort algorithm
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
      left++;
      right--;
    }
  }
  temp = A[right];
  A[right] = A[0];
  A[0] = temp;

  return right; // return the value of the index where pivot is located
}

int middle(int* A, int right) // this is helper function to find the median among a[0], a[n/2], a[n-1]
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
  if(n<=1) // This is for the case where n <=2, since for these, we  cannot find 3 values to pick the median
  {
    return;
  }
  if(n==2)
  {
    if(A[0] <= A[1])
    {
      return; // if length 2 array is already sorted, just finish sorting
    }
    else // if it is not sorted, then sort it.
    {
      int t = A[0];
      A[0] = A[1];
      A[1] = t;
      return;
    }
  }
  int pivot_idx = middle(A, n); // get the median as the pivot index, 
  int pivot = A[pivot_idx]; // and let the median to be the first value, index=0
  int temp = A[0];
  A[0] = A[pivot_idx];
  A[pivot_idx] = temp;
  int left = 1;
  int right = n-1;
  while(left <= right) // start quick sort algorithm
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
      left++;
      right--;
    }
  }
  temp = A[right];
  A[right] = A[0];
  A[0] = temp;
  quick_sort(A, right); // by recursion, sorting the array. The stopping condition is for n<=2, written above
  quick_sort(A+right+1, n-right-1);
}

int compare(const void* first, const void* second) // declare the function as int, since this will return the int values
{
  // this is for the compare function of the qsort function.
  point* one = (point*)first; // since each input values will the struct values,
	point* two = (point*)second; // for comparing to value, we declare the value as the struct element

  int x1 = one->x; // get the x, y values from the given struct element
  int y1 = one->y;
  int x2 = two->x;
  int y2 = two->y;
	if (x1*x1 + y1*y1 < x2*x2 + y2*y2) // compare the  distance from the (0, 0)
		return -1;
	else if (x1*x1 + y1*y1 > x2*x2 + y2*y2)
		return 1;
	else // if the distance from (0,0) is same,
	{
		if (x1 < x2) // then just compare the x values of them as written in the question.
			return -1;
		else
			return 1;
	}
	return 0;
}


void sort_points(point* A, int length) {
  //   point A[6] = {{3,2}, {7,1}, {1,1}, {3,4}, {5,0}, {7,1}};
  qsort(A, length, sizeof(A[0]), compare); // use the qsort function, with the compare function written above.
}

int find(int* A, int n, bool (*pred)(int)) {
  // implement me
  // for the given boolean condition, find the index that makes the boolean condition ture
  for(int i = 0; i < n; i++) //from the beginning to find the smallest index
  {
    if(pred(A[i]) != 0)
    {
      return i;
    }
  }
  return -1; // if there is no value satisfying return -1
}


void map(int* A, int n, int (*f)(int)) {
  // implement me
  for(int i = 0; i < n; i++) // with the given function f, apply it to each element of the array
  {
    A[i] = f(A[i]); // so converting the element to the values returned by given function.
  }
}


int reduce(int* A, int n, int (*f)(int,int)) {
  // implement me
  if(n<=0) // if the given array doesn't have at least two values, return NULL
  {
    return -1;
  }
  int result = A[0]; // start with A[0]
  for(int i = 1; i < n; i++)
  {
    result = f(result, A[i]); // and cumulate them into the result variable
  }
  return result;
}
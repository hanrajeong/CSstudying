#define DEBUG_TEST 1

#include <stdio.h>

int binary_search_rec_helper(int* A, int start, int end, int item) {
  if (start>end)
    return -1;
  
  int mid = (start+end)/2;

  if (DEBUG_TEST)
    printf("DEBUG: start=%d, mid = %d, end=%d\n", start,mid,end);
  
  if (item == A[mid])
    return mid;
  else if (item < A[mid])
    return binary_search_rec_helper(A, start, mid-1, item);
  else
    return binary_search_rec_helper(A, mid+1, end, item);
}

int binary_search_rec(int* A, int n, int item) {
   return binary_search_rec_helper(A, 0, n, item);
}



int binary_search_rec2(int* A, int n, int item) {

  // stopping conditions
  if (n == 0)
    return -1;

  int mid = n/2;


  if (DEBUG_TEST) {
    printf("DEBUG: ");
    for (int i=0; i < n; i++)
      printf("%d ", A[i]);
    printf("\n mid = %d\n", mid);
  }

  // another stopping conditions
  if (A[mid]==item)
    return mid;
  
  // recursive calls
  if (A[mid] > item) { // if item < A[mid] return the index
    int i = binary_search_rec2(A, mid, item);
    if (i == -1) // item not found
      return -1;
    else  // return the index
      return i;
  }
  else  {
    int i = binary_search_rec2(A+mid+1, n-mid-1, item);
    if (i == -1)  // item not found
      return -1;
    else     // i is the relative index, need to adjust to the absolute index in A
      return mid+1+i;
  }
}

int main() {
  int arr[] = {1,2,4,5,7,10,15,20};
  int item = 6;
  int ind = binary_search_rec(arr,8,item);
  if (ind>=0)
    printf("%d found in A[%d]\n", item, ind);
  else
    printf("item not found\n");
  return 0;
}

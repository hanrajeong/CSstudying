#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_pair.h"


/************************************************/
/*********  helper functions    *****************/
/************************************************/

void print_array(int* ar, int n) {
  for (int i=0; i < n; i++)
    printf("%d ", ar[i]);
  printf("\n");
}


void swap(int* a, int* b){
  int tmp = *a; 
  *a = *b;
  *b = tmp; 
}
/************************************************/
/*********  helper functions    *****************/
/************************************************/

// rearrange - wrong implementation
int rearrange(int *ar, int n, int pivot_index){

  if (n<=1)
    return n;

  int pivot_value = ar[pivot_index]; 

  // swap pivot to ar[0]
  swap(&ar[0], &ar[pivot_index]); 

  int* tmp = (int*) malloc(n*sizeof(int));
  int left_ptr=0, right_ptr=n-1;
  
  for (int i=1;i<n;i++) {
      if (ar[i] <= pivot_value) 
        tmp[left_ptr++] = ar[i];
      else
        tmp[right_ptr--] = ar[i];
//    printf("%d %d\n", left_ptr, right_ptr);
  }
  tmp[left_ptr] = pivot_value;
  
  memcpy(ar, tmp, n*sizeof(int));
  free(tmp);
  
//  printf("%d %d\n", left_ptr, right_ptr);
  return left_ptr;
}

// gets an array of length n
// implements quick sort without recursion
void quick_sort_item(int* ar, int n) {

  // stack of pairs
  // pairs contains the first index and the last index  of the subarray
  stack_t* s = stack_create();

  stack_push(s, (pair){0,n-1}); 

  int pivot_ind,rel_pivot_ind;
  
  while (!stack_is_empty(s)) {
    pair next = stack_pop(s);

    rel_pivot_ind = rearrange(ar+next.first, next.second-next.first+1, 0);
    pivot_ind = rel_pivot_ind+next.first;

    if (pivot_ind+1<next.second)
      stack_push(s,(pair){pivot_ind+1,next.second});

    if (pivot_ind-1>next.first)
      stack_push(s,(pair){next.first, pivot_ind-1});

  } // end of while loop

  free(s);
}

int main() {

  int a[] = {4,1,8,5,7,3,22,1,17,4,9};
  int n = 11;
//  rearrange(a,7,0);
  quick_sort_item(a,n);

  print_array(a,n);
  return 0;
}
 
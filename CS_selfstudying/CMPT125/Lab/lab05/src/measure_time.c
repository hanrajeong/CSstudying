#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

// #include "point_array.h"

void find_duplicates(int* a, int len) {
  for (int i=0;i<len;i++)
    for (int j=0; j < i; j++)
      if (a[i] == a[j]) {
        printf("The indices: %d, %d ", i,j);
        printf("have the same value %d\n", a[i]);
        return;
      }
}

void find_item(int* a, int len, int item) {
  for (int i=0;i<len;i++) {
    if (a[i] == item) {
        printf("Item %d found in inxed %d\n", item, i);
        return;
      }
  }
  // if reached here, item not found
  printf("Item %d not found\n", item);
    
}



int main() {
  struct timeval current_time;

  int len = 100000;
  int* ar = (int*) malloc(len*sizeof(int));
  // fill the array with random numbers
  for ( unsigned int i = 0; i < len; i++ ) 
    ar[i] = rand();


  gettimeofday(&current_time, NULL);
  printf("seconds : %ld, micro seconds : %ld\n",
    current_time.tv_sec, current_time.tv_usec);

  find_duplicates(ar, len); 

  gettimeofday(&current_time, NULL);
  printf("seconds : %ld, micro seconds : %ld\n",
    current_time.tv_sec, current_time.tv_usec);

  find_item(ar, len, ar[len/2]); 

  gettimeofday(&current_time, NULL);
  printf("seconds : %ld, micro seconds : %ld\n",
    current_time.tv_sec, current_time.tv_usec);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_array.h"

my_array* create_my_array(const char* nm, int init_size) {
    my_array* ar = (my_array*)malloc(sizeof(my_array));
    ar->name = nm;
    ar->data = (int*)malloc(init_size*sizeof(int));
    ar->length=0;
    ar->capacity= init_size;
    return ar;
}


int get_length(const my_array* ar) {
  return ar->length;
}


int get(const my_array* ar, int index) {
  return ar->data[index];
}

int set(my_array* ar, int index, int value) {
  return ar->data[index] = value;
}

// increases the length of the array by 1
// and sets new_value in the last entry
int append(my_array* ar, int new_value) {
  // if the array is full
  // incease the capacity of the arrray by 1
  if (ar->length == ar->capacity) {
    ar->data = (int*)realloc(ar->data, (ar->capacity+1)*sizeof(int));
    ar->capacity++;
  }
  // set the value as the last element
  // and increase the length
  ar->data[ar->length++] = new_value;
  return new_value;
}

void extend(my_array* ar1, const my_array* ar2) {
  // implement me
}


// prints all elements of the array
void print_my_array(const my_array* ar) {
  printf("%s = [ ", ar->name);
  int i;
  for (i=0; i<ar->length; i++)
    printf("%d ", ar->data[i]);
  
  printf("] :: length = %d\n", ar->length);
}

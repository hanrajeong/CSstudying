#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  const char* name;
  int* data;
  int length;
  int capacity;
} my_array;

my_array* create_my_array(const char* name, int init_size)
{
  my_array* ar = (my_array*)malloc(sizeof(my_array));
  if(ar==NULL)
    return NULL;
  ar->name = name;
  ar->data = (int*)malloc(init_size*sizeof(int));
  ar->length = 0;
  ar->capacity = init_size;
  return ar;
}

int get_length(const my_array* ar)
{
  return ar->length;
}

int get(const my_array* ar, int index)
{
  return ar->data[index];
}

int set(const my_array* ar, int index, int value)
{
  ar->data[index] = value;
  return value;
}

int append(my_array* ar, int new_value)
{
  if(ar->length == ar->capacity)
  {
    ar->data = (int*)realloc(ar->data, (ar->capacity+1)*sizeof(int));
    ar->capacity++;
  }
  ar->data[ar->length] = new_value;
  ar->length++;
}

void extend(my_array* ar1, my_array* ar2)
{
  int len1 = get_length(ar1);
  int len2 = get_length(ar2);
  if(ar1->capacity < len1+len2)
  {
    ar1->data = (int*)realloc(ar1->data, (len1+len2)*sizeof(int));
  }
  for(int i=0; i<len2; i++)
    append(ar1, ar2->data[i]);
}

// prints all elements of the array
void print_my_array(const my_array* ar) {
  printf("%s = [ ", ar->name);
  int i;
  for (i=0; i<ar->length; i++)
    printf("%d ", ar->data[i]);
  
  printf("] :: length = %d\n", ar->length);
}



int main()  {
  my_array* ar = create_my_array("ARRAY1", 5);
  append(ar, 1);
  append(ar, 3);
  append(ar, 5);
  append(ar, 7);
  append(ar, 9);
  append(ar, 11);
  print_my_array(ar);
  set(ar, 0, 100);
  append(ar, 13);
  append(ar, 15);
  print_my_array(ar);
  printf("\n----\n");
  printf("----\n");

  my_array* ar2 = create_my_array("ARRAY2", 100);
  append(ar2, 10);
  append(ar2, 20);
  append(ar2, 30);
  append(ar2, 40);
  append(ar2, 50);
  print_my_array(ar2);
  set(ar2, 3, -60);
  print_my_array(ar2);
  extend(ar2, ar);
  print_my_array(ar2);


  // 1) create an an array with random numbers
  // 2) set the length to be 100, 10^6, 10^8
  // 3) see how long it takes to add new elements to the array using gettime function
  // 4) change the add() function as follows:
  // instead of increasing capacity by 1 each time
  // (i) increase it by 100
  // (ii) double the capacity
  // (iii) try other increase functions
  // see how this affects the running time
  my_array* rand_ar = create_my_array("RANDOM ARRAY", 10);
  int length = 100;
  int i;
  for(i=0;i<length;i++)
    append(rand_ar, rand());
  return 0;
}

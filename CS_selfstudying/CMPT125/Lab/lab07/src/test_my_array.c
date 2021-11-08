#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "my_array.h"


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

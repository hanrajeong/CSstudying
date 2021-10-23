#include <stdio.h>
#include <stdlib.h>

void print_ar(int* ar, int len,const char* name) {
  printf("%s = [", name);
  for (int i=0;i<len; i++)
    printf(" %d", ar[i]);
  printf("]\n");
}

int main() {
  int* ar1 = (int*) malloc(5*sizeof(int));
//  printf("address of ar1 = %p\n", ar1);
  for (int i=0;i<5; i++)
    ar1[i] = i;


  print_ar(ar1, 5, "ar1");
  free(ar1);

  print_ar(ar1, 5, "after free ar1:");

  int* ar2 = (int*) malloc(5*sizeof(int));
//  printf("address of ar2 = %p\n", ar2);
  for (int i=0;i<5; i++)
    ar2[i] = i+20;

  

  print_ar(ar2, 5, "ar2");

  

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

int* foo(int start){
  int* arr = (int*)malloc(3*sizeof(int));
  arr[0] = start;
  arr[1] = start +1;
  arr[2] = start +2;
  // int* ret = arr;

  return arr;
}

int main()
{
  int *a1 = foo(0);
  int *a2 = foo(3);

  printf("a1 = [%d, %d, %d]\n", a1[0], a1[1], a1[2]);
  printf("a2 = [%d, %d, %d]\n", a2[0], a2[1], a2[2]);

  return 0;
}
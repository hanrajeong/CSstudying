#include <stdio.h>
#include <stdlib.h>

int* array_of_squares(int n)
{ 
  int* ret = (int*) malloc(n * sizeof(int)); //malloc은 runtile 떄 실행됨.
  if (ret == NULL)
    return NULL;

  for (int i = 0; i < n; i++)
    ret[i] = i*i;

  return ret;
}

int main() { 
  int size = 10;
  int* a = array_of_squares(size);
  if (a == NULL)
  {
    printf("malloc failed");
    return -1;
  }                              

  for (int i = 0; i < size; i++)
    printf("a[%d] = %d\n", i, a[i] );
                     
//  a = (int*) malloc(10 * sizeof(int)); //!! Oh no!! memory leak!!!

  free(a); // Don't forget to free the memory!!!!!!

  return 0;
}
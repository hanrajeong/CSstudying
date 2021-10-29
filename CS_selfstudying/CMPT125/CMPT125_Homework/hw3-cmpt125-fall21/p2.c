#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_even(int x) { return x%2 == 0; }
bool is_positive(int x) { return x>0; }

int find(int* A, int n, bool (*pred)(int)) {
  // implement me
  for(int i = 0; i < n; i++)
  {
    if(pred(A[i]) != 0)
    {
      return i;
    }
  }
  return -1;
}

int main()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (find(A, 6, is_even)==2 && find(A, 6, is_positive)==1) 
    printf("Q3-find ok\n");
  else
    printf("Q3-find ERROR\n");
}


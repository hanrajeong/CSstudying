#include <stdio.h>
#include <stdlib.h>

int* create_array(int start)
{
  int* ar = (int*)malloc(3*sizeof(int));

  for(int i = 0; i<3; i++)
  {
    ar[i] = i;
  }
  return ar;
}

int main()
{
  int* ar1 = create_array(0);
  int* ar2 = create_array(3);

  for(int i = 0; i<3; i++)
  {
    printf("%d ", ar1[i]);
  }

  for(int j = 0; j<3; j++)
  {
    printf("%d ", ar2[j]);
  }
}
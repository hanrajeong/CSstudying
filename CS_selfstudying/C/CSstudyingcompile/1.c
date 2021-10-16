#include <stdio.h>
#include <stdlib.h>

int* create_arry(int start)
{
  int ar[3];

  for (int i=0;i<3;i++)
  {
    ar[i] = i;
  }

  int* ret = ar;
  return ret;
}

int main()
{
  int* ar1 = create_array(0);
  int* ar2 = create_array(3);

  for(int i = 0; i<3; i++)
  {
    printf("%d", ar1[i]);
  }

  for(int i = 0; i<3; i++)
  {
    printf("%d", ar2[i]);
  }
  printf("\n");

  return 0;
}
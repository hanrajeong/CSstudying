#include <stdio.h>
#include <stdlib.h>

int* create_const_array(int len, int val)
{
  int* ret = (int*)malloc(len*sizeof(int));
  for(int i = 0; i < len; i++)
  {
    ret[i] = val;
  }
  return ret;
}

int main(void)
{
  int* a = create_const_array(10, 1);
  for(int i = 0; i < 10; i++)
  {
    printf("%d ", a[i]);
  }
}
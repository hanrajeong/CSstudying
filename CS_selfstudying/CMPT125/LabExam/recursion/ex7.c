#include <stdio.h>
#include <stdbool.h>

bool foo2(int* a, int len)
{
  if(len<=1)
    return true;
  int mid = len/2;
  bool b1 = foo2(a, mid);
  bool b2 = foo2(a+mid, len-mid);
  return (b1 && b2 && a[mid-1] <= a[mid]);
}

bool foo3(int* a, int len)
{
  int mid = len/2;
  return (a[mid-1] <= a[mid]);
}

int main(void)
{
  int a[10] = {1, 2, 3, 4, 15, 6, 7, 8, 9, 10};
  printf(foo2(a, 10) ? "true" : "false");
  printf("\n");
  printf(foo3(a, 10) ? "true" : "false");
}
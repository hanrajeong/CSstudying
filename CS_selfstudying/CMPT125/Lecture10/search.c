#include <stdio.h>

int binary_search(int* ar, int len, int n)
{
  if(n<=0)
    return -1;
  int found;
  int mid = len/2;
  if(ar[mid]==n)
    found = mid;
  else if(n<ar[mid])
    found = binary_search(ar, mid, n);
  else
  {
    found = binary_search(ar+mid+1, n-mid-1, n);
    if(found != -1)
      return found+mid+1;
    else
      return -1;
  }
}

int binary_search2(int* ar, int len, int n)
{
  int start = 0;
  int end = len-1;
  int mid;
  while(start<end)
  {
    mid = (start+end)/2;
    if(ar[mid] == n)
    {
      return mid;
    }
    else if(ar[mid]>n)
    {
      end = mid-1;
    }
    else
    {
      start = mid+1;
    }
  }
  return -1;
}

int main(void)
{
  int ar[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("%d ", binary_search(ar, 10, 5));
  printf("\n");
  printf("%d ", binary_search2(ar, 10, 5));
}
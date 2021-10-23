#include <stdio.h>
#include <stdbool.h>

// bool foo2(int* a, int len) {
//   if (len <= 1)
//     return true;
 
//   int mid = len/2; // round down if len is odd
//   bool b1 = foo2(a, mid);
//   bool b2 = foo2(a+mid, len-mid);
//   return (b1 && b2 && a[mid-1] <= a[mid]);
// }

bool foo2(int *a, int len)
{
  for(int i = 0; i < len-1; i++)
  {
    if(a[i] > a[i+1])
    {
      return false;
    }
  }
  return true;
}

int main(void)
{
  int ar[8] = {1, 2, 3, 6, 10, 7, 8, 9};
  int *arr = ar;

  printf(foo2(arr, 8) ? "true" : "false");
}
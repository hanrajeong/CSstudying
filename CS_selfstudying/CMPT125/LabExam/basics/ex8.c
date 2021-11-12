#include <stdio.h>
#include <stdbool.h>

bool check_bigger(int* arr1, int* arr2, int n)
{
  for(int i = 0 ; i< n; i++)
  {
    if(arr1[i] >= arr2[i])
      return false;
  }
  return true;
}

int main(void)
{
  int a1[5] = {1, 2, 3, 4, 5};
  int a2[5] = {2, 3, 4, 5, -6};
  printf(check_bigger(a1, a2, 5) ? "true" : "false");
}
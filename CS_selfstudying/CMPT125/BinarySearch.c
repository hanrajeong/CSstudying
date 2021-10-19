#include <stdio.h>

int binarysearch(int arr[], int number, int start, int end)
{
  int mid = (start + end) / 2;

  if(start > end)
  {
    return -1;
  }

  if(arr[mid] == number)
  {
    return mid;
  }
  else if(arr[mid] > number)
  {
    return binarysearch(arr, number, start, mid-1);
  }
  else
  {
    return binarysearch(arr, number, mid+1, end);
  }
}

int main(void)
{
  int number = 19;
  int arr[10] = {1, 3, 6, 8, 9, 10, 14, 19 , 40, 90};
  int start = 0;
  int end = 9;

  int index = binarysearch(arr, number, start, end);

  printf("%d", index);

  return 0;
}
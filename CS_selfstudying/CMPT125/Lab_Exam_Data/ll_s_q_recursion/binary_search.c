#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binary_search_helper(int* ar, int start, int end, int item)
{
  if(start > end)
    return -1;
  int mid = (start + end)/2;
  if(ar[mid] == item)
    return mid;
  else if(ar[mid]>item)
    return binary_search_helper(ar, start, mid-1, item);
  else
    return binary_search_helper(ar, mid+1, end, item);
}

int binary_search(int* ar, int n, int item)
{
  return binary_search_helper(ar, 0, n-1, item);
}

int binary_search2(int* ar, int n, int item)
{
  int index;
  if(n<=0)
    return -1;
  int mid = n/2;
  if(ar[mid]==item)
    index = mid;
  else if(ar[mid]>item)
  {
    index = binary_search2(ar, mid, item);
    if(index != -1)
      return index;
    else
      return -1;
  }
  else
  {
    index = binary_search2(ar+mid+1, n-mid-1, item);
    if(index != -1)
      return index + mid + 1;
    else
      return -1;
  }
}

int main() 
{
  // int arr[] = {1,2,4,5,7,10,15,20};
  int arr[] = {1};
  int item = 20;
  int ind = binary_search(arr,1,item);
  if (ind>=0)
    printf("%d found in A[%d]\n", item, ind);
  else
    printf("item not found\n");
  return 0;
}

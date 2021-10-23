#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linear_search_rec_first(int* ar, int length, int number) {
  printf("%d", sizeof(ar));
}

int main(void)
{
  int arr[6] = {1, 2, 3, 4, 2, 1};
  linear_search_rec_first(arr, 6, 3);
}
#include <stdio.h>
#include <stdlib.h>

// implement a program that get an array of ints and increase each value by 1 and print the array

int main(void)
{
  int len;
  printf("please type the lenth of array: ");
  scanf("%d", &len);

  int *arr = (int*)malloc(len*sizeof(int));

  printf("please type the numbers: ");
  for(int i = 0; i<len; i++)
  {
    scanf("%d", &arr[i]);
  }

  for(int j = 0; j<len; j++)
  {
    printf("%d ", arr[j]+1);
  }
}
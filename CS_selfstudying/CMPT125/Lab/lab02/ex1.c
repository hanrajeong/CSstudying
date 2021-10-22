#include <stdio.h>
#include <stdlib.h>

// implement a program that get array of integeers and print the max

int main(void)
{
  int len;

  printf("please enter the size of numbers you want to implement: ");
  scanf("%d", &len);

  int *arr = (int*)malloc(len*sizeof(int));

  printf("please type the number you want to put in the array: ");
  for(int i = 0; i < len; i++)
  {
    scanf("%d", &arr[i]);
  }

  int max = arr[0];

  for(int j = 1; j < len; j++)
  {
    if(max < arr[j])
    {
      max = arr[j];
    }
  }

  printf("the maximum is %d", max);
}
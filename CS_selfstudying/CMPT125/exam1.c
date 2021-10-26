#include <stdio.h>
#include <stdlib.h>

void d(int n)
{
  int temp;
  int *arr = (int*)malloc(sizeof(int)*n);
  printf("please enter the %d values ", n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &temp);
    *(arr+i) = temp;
  }
  for(int j = n-1; j >= 0; j--)
  {
    printf("%d", *(arr+j));
  }
}

int main(void)
{
  d(3);
}
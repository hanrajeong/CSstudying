#include <stdio.h>
#include <stdlib.h>

void read_and_print_reverse(int n)
{
  int temp;
  int* numbers = (int*)malloc(n*sizeof(int));
  printf("please type %d numbers ", n);
  for(int i = 0; i<n; i++)
  {
    scanf("%d", &temp);
    *(numbers+i) = temp;
  }
  for(int j = n-1; j >= 0; j--)
  {
    printf("%d ", *(numbers+j));
  }
}

int main(void)
{
  read_and_print_reverse(5);
}
#include <stdio.h>
#include <stdlib.h>

void print_max_number(const int digits[], int n)
{
  int* new = (int*)malloc(n*sizeof(int));
  for(int k = 0; k<n; k++)
  {
    new[k] = digits[k];
  }
  int i, j;
  for(i=1; i<n; i++)
  {
    int p = new[i];
    j=i-1;
    while(j>=0 && new[j]>p)
    {
      new[j+1] = new[j];
      j--;
    }
    new[j+1] = p;
  }
  for(i=n-1; i>=0; i--)
    printf("%d", new[i]);
}

int main(void)
{
  int n[5] = {1, 6, 3, 5, 2};
  print_max_number(n, 5);
}
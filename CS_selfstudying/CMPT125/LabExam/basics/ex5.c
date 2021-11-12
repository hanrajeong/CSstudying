#include <stdio.h>

int max(const int array[], int n)
{
  int max = array[0];
  for(int i = 1; i < n; i++)
  {
    if(max < array[i])
    {
      max = array[i];
    }
  }
  return max;
}

int main()
{
  int array[8] = {1, 2, 3, 4, 5, 6, 10, 5};
  printf("Maximum element is %d", max(array, 8));
  return 0;
}
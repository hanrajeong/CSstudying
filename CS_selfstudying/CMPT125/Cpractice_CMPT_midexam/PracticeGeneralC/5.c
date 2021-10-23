#include <stdio.h>
#include <stdlib.h>

int max(const int array[], int n)
{
	int max_val = array[0];
	for (int i = 0; i < n; i++)
	{
		if(max_val < array[i])
		{
			max_val = array[i];
		}
	}
  return max_val;
}

int main(void)
{
  int array[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;

  printf("%d", max(array, n));

  return 0;
}
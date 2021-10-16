// An array of ints of length n -> returns 0 if all distinct, returns 1 for otherwise

#include <stdio.h>

int check(int *arr, int n)
{
  for(int p = 0; p < n - 1; p++)
  {
    for(int k = p + 1; k < n; k++)
    {
      if(arr[k] == arr[p])
      {
        return 1;
      }
    }
  }
  return 0;
}

int main()
{
  int n;
  printf("what size of array you want to check? ");
  scanf("%d", &n);

  int arr[n];
  printf("please type the array you want to check: ");
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int result = check(arr, n);

  printf("%d", result);

  return 0;
}
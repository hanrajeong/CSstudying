// Two examples from Lecture 08, second example

#include <stdio.h>

// An array of ints of length n -> returns 0 if all distinct, returns 1 for otherwise

#include <stdio.h>

int check(int *arr, int *check_arr, int n)
{
  for(int p = 0; p < n; p++)
  {
    for(int i = 0; i < n + 1; i++)
    {
      if(arr[p] == i)
      {
        // printf("comparing arr[%d] & %d, the value is %d\n", p, i, arr[p]);
        check_arr[i] = 1;
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

  // for(int l = 0; l < n; l++)
  // {
  //   printf("%d ", arr[l]);
  // }
  // printf("\n");

  int check_arr[n + 1];
  for(int a = 0; a < n + 1; a++)
  {
    check_arr[a] = 0;
  }

  // for(int b = 0; b < n + 1; b++)
  // {
  //   printf("%d ", check_arr[b]);
  // }
  // printf("\n");

  int result = check(arr, check_arr, n);
  int index = 0;
  for(int i = 0; i < n + 1; i++)
  {
    // printf("%d ", check_arr[i]);
    if(check_arr[i] == 0)
    {
      index = i;
    }
  }

  printf("\n");

  printf("%d", index);

  return index;
}
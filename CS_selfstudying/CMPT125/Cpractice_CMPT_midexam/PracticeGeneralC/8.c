#include <stdio.h>
#include <stdbool.h>

// int same(int a[], int b[], int n, int m)
// {
//   int check = 0;
//   if (n!=m)
//   {
//     return check;
//   }
//   for(int i = 0; i < n; i++)
//   {
//     if(a[i] == b[i])
//     {
//       check = 1;
//     }
//     else
//     {
//       check = 0;
//     }
//   }
//   return check;
// }

bool same(int a[], int b[], int n, int m)
{
  if(n!=m)
  {
    return false;
  }
  for(int i = 0; i < n; i++)
  {
    if(a[i]!=b[i])
    {
      return false;
    }
  }
  return true;
}

int main(void)
{
  int a[7] = {1, 2, 3, 4, 5, 6, 7};
  int b[7] = {1, 2, 3, 4, 5, 6, 7};

  printf("%d", same(a, b, 7, 7));

  return 0;
}
#include <stdio.h>

// int foo(int n) {
//   if (n == 0)
//     printf("0 ");
//   else {
//     printf("%d ", n);
//     foo(n-1);
//     printf("%d ", n);
//   }
// }

int foo(int n)
{
  for(int i = n; i>=0; i--)
  {
    printf("%d ", i);
  }
  for(int j = 1; j <= n; j++)
  {
    printf("%d ", j);
  }
}

int main(void)
{
  int n = 10;

  foo(10);
}
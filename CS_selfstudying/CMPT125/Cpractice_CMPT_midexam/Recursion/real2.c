#include <stdio.h>

// void foo(int n)
// {
//   for (int i = 1; i <= n; i++)
//   {
//     printf("%d ", i);
//   }
// }

void foo(int n) {
  if (n > 0) {
    foo(n-1);
   	printf("%d ", n);
  }
}

int main(void)
{
  foo(10);
}
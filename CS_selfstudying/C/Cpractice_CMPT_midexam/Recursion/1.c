#include <stdio.h>

void foo1(int n) {
  if (n > 0) {
    printf("%d ", n);
    foo1(n-1);
   	printf("%d ", n);
    
  }
}

// void foo1(int n)
// {
//   for (int i = 0; i < n; i++)
//   {
//     printf("%d ", (n-i));
//   }
// }

int main(void)
{
  foo1(3);
  printf("\n");
  foo1(5);
  printf("\n");
  foo1(10);
}
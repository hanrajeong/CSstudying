#include <stdio.h>
#include <math.h>

// long foo(int n) {
//   if (n==0) return 1;
//   else return foo(n-1)+foo(n-1);
//   }

long foo(int n)
{
  return pow(2, n);
}


int main(void)
{
  printf("%d", foo(3));
}
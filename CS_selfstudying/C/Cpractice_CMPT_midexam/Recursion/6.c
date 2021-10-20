#include <stdio.h>


int foo1(int n) {
  if (n <= 1)
    return n*2;
 	
  int half = n/2; // round down if n is odd
  int n1 = foo1(half);
  int n2 = foo1(n-half);
  return (n1+n2);
}

int main(void)
{
  printf("%d",foo1(70));
}
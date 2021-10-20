#include <stdio.h>

long foo(int n) {
  if (n==0) return 1;
  else return foo(n-1)+foo(n-1);
  
}

int main(void)
{
   long result = foo(10);

   printf("%ld", result);
}
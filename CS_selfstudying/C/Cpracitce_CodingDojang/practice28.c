#include <stdio.h>

int fib(int n)
{
    if(n<=0)
    {
        return 1;
    }
    else if(n==1)
    {
        return 1;
    }
    
    return fib(n-1) + fib(n-2);
}

int main(void)
{
  printf("%d", fib(10));

  return 0;
}
#include <stdio.h>

int bar(int a, int n)
{
  if(n==0)
    return 0;
  int half = n/2;
  int tmp = bar(a, half);
  if(n%2 == 0)
    return tmp+tmp;
  else
    return tmp+tmp+a;
}

int bar2(int a, int n)
{
  return a*n;
}

int main(void)
{
  printf("%d\n", bar(10, 8));
  printf("%d\n", bar2(10, 8));
}
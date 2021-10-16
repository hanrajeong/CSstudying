#include <stdio.h>

int bar(int size)
{
  int i = size + 1;
  return i;
}

int foo (int n)
{
  int ret = 3;
  printf("%d\n", bar(4));
  printf("%d\n", bar(8));
  return ret;
}

int main()
{
  int a = foo(5);
  printf("%d", a);
  return 0;
}
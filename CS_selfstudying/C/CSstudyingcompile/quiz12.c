#include <stdio.h>

char foo(char x)
{
  x = 'b';
  return x;
}

int main()
{
  const char ch = 'a';

  char ca = foo(ch);
  printf("ch = %c", ca);

  return 0;
}
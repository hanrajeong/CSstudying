#include <stdio.h>

int main()
{
  char *ptr = "hello";
  *(ptr) = 'H';
  printf("%s\n", ptr);
  return 0;
}
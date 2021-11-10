#include <stdio.h>

int main()
{
  char* s = "Programming is FUN!!";
  int i = 0;

  while(s[i]!='\0')
  {
    i++;
  }

  printf("Length of the string: %d", i);
  return 0;
}
#include <stdio.h>
#include <string.h>

int str_find(const char* str, char c)
{
  for(int i = 0; i < strlen(str); i++)
  {
    if(str[i] == c)
      return i;
  }
  return -1;
}

int main(void)
{
  char* str = "hello world";
  printf("%d", str_find(str, 'l'));
}
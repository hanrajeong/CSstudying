#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_palindrome(const char* str)
{
  int count = 0;
  int i = 0;
  
  while (str[i] != '\0')
  {
    count++;
  }
  char *st = (char*)malloc(count*sizeof(char));
  strcpy(st, str);

  if(count <= 1)
  {
    return true;
  }
  if(st[0] == st[count])
  {
    st[count] = '\0';
    return is_palindrome(st+1);
  }
  else
    return false;
}

int main(void)
{
  char str[] = "Hello";
  char *ptr = str;

  printf(is_palindrome(ptr) ? "true" : "false");
}
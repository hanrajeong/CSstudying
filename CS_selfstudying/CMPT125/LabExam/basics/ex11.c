#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char* str)
{
  int len = strlen(str);
  for(int i = 0; i<len/2; i++)
  {
    if(str[i] != str[len-i-1])
      return false;
  }
  return true;
}

int main(void)
{
  char* str = "racecar";
  printf(is_palindrome(str) ? "true" : "false");
}
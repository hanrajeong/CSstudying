#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome(const char* str, int len)
{
  if(len<=1)
    return true;
  if(str[0] != str[len-1])
    return false;
  else
  {
    return palindrome(str+1, len-2);
  }
}

bool is_palindrome(const char* str)
{
  palindrome(str, strlen(str));
}

int main(void)
{
  char* str = "racecar";
  printf(is_palindrome(str) ? "true" : "false");
}
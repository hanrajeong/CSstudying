#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// int str_find(const char* str)
// {
//   int result = false;
//   int i = 0;
//   int size = 0;
//   while(str[i]!='\0')
//   {
//     size++;
//     i++;
//   }
//   for (int j = 0; j < (size/2); j++)
//   {
//     if(str[j] == str[size-j-1])
//     {
//       result = true;
//     }
//     else
//     {
//       result = false;
//       return result;
//     }
//   }
//   return result;
// }

bool is_palindrome(const char* str)
{
  int len = strlen(str);
  for (int i = 0; i<len/2; i++)
  {
    if(str[i] != str[len-i-1])
    {
      return false;
    }
  }
  return true;
}

int main(void)
{
  char* str = "raccara";

  printf(is_palindrome(str) ? "true" : "false");

  return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// bool is_palindrome(const char* str)
// {
//   int count = 0;
//   int i = 0;
  
//   while (str[i] != '\0')
//   {
//     count++;
//   }

//   char *s = (char*)malloc(count*sizeof(char));
//   strcpy(s, str);

//   if(count <= 1)
//   {
//     return true;
//   }
//   if(s[0] == s[count])
//   {
//     s[count] = '\0';
//     return is_palindrome(s+1);
//   }
//   else
//     return false;
// }

bool is_palindrome(const char* str)
{
  int len = strlen(str);
  int h = len/2;
  for(int i = 0; i < h; i++)
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
  char str[] = "rae car";
  char *ptr = str;

  printf(is_palindrome(ptr) ? "true" : "false");
}
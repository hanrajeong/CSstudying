#include <stdio.h>
#include <string.h>

// int str_find(const char* str, char c)
// {
//   int i = 0;
//   while(1)
//   {
//     printf("str[i]= %c\n", str[i]);
//     if(str[i]=='\0')
//     {
//       break;
//     }
//     else if(str[i]==c)
//     {
//       return i;
//     }
//     i++;
//   }
//   return -1;
// }

int str_find(const char* str, char c)
{
  int len = strlen(str);
  for(int i = 0; i < len; i++)
  {
    if(str[i] == c)
    {
      return i;
    }
  }
  return -1;
}

int main(void)
{
  char* str = "Hellodddd";

  printf("%d", str_find(str, 'd'));
}
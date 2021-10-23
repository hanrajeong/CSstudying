#include <stdio.h>
#include <string.h>

// void reverse(char str[])
// {
//   int size = 0;
//   int i = 0;
//   while(str[i]!='\0')
//   {
//     size++;
//     i++;
//   }
//   char new[size];
//   for (int j = 0; j < size; j++)
//   {
//     new[j] = str[size-j-1];
//   }
//   for(int k =0; k<size; k++)
//   {
//     printf("%c", new[k]);
//   }
// }

void reverse(char str[])
{
  int len = strlen(str);
  char s[len];
  for(int i = 0; i <len; i++)
  {
    s[i] = str[len - i -1];
  }
  s[len] = '\0';
  for(int j = 0; j < len; j++)
  {
    str[j] = s[j];
  }
}

int main(void)
{
  char str[] = "Hello";
  reverse(str);
  printf("%s", str);

  return 0;
}
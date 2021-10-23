#include <stdio.h>
#include <string.h>

void str_reverse_iter(char *str)
{
  int length = strlen(str);
  char copy[length]; // the copy of the string to be reversed
  for (int i = 0; i < length; i++)
  {
    copy[i] = str[i];
  }
  int o = 0;
  for(int p = 0; p < length; p++)
  {
    printf("%c", copy[p]);
  }
  printf("\n");
  for(int k = length-1; k >= 0; k--)
  {
    printf("%d %d \n", k, o);
    printf("%c %c \n", str[k], copy[o]);
    str[k] = copy[o]; // this is where the error is
    o++;
  }
}

int main(void)
{
  char *s = "hello";

  str_reverse_iter(s);
  printf("%s", s);
}
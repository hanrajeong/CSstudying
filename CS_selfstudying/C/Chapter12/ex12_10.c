//버블 정렬 알고리즘

#include <stdio.h>
#include <string.h>

void bubble(char*, int);

int main(void)
{
  char str[80];

  printf("Please type the string: ");
  gets(str);
  bubble(str, strlen(str));

  printf("The result is %s", str);

  return 0;
}

void bubble(char *item, int length)
{
  for(int i = 0; i < length; i++)
  {
    for(int j = 0; j < length -1 -i; j++)
    {
      if(item[j] > item[j+1])
      {
        char temp = item[j];
        item[j] = item[j+1];
        item[j+1] = temp;
      }
    }
  }
}
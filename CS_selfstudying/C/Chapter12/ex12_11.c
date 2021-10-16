#include <stdio.h>
#include <string.h>

void selection(char *, int);

int main(void)
{

  char str[100];
  
  printf("please type the string: ");
  gets(str);

  selection(str, strlen(str));

  printf("The result is %s\n", str);
  return 0;
}

void selection(char *item, int count)
{
  char small;
  int k;
  
  for(int i = 0; i < count; i++)
  {
    small = item[i];
    k = i;
    for(int j = i+1; j < count; j++)
    {
      if(item[j] < small)
      {
        small = item[j];
        k = j;
      }
    }
    item[k] = item[i];
    item[i] = small;
  }
}
#include <stdio.h>

void reverse(char str[])
{
  int size = 0;
  int i = 0;
  while(str[i]!='\0')
  {
    size++;
    i++;
  }
  char new[size];
  for (int j = 0; j < size; j++)
  {
    new[j] = str[size-j-1];
  }
  for(int k =0; k<size; k++)
  {
    printf("%c", new[k]);
  }
}

int main(void)
{
  char str[] = "Hello";
  
  reverse(str);

  return 0;
}
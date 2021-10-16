#include <stdio.h>
#include <string.h>

int sequential(char*, int, char);

int main(void)
{
  char str[100];
  char op;
  int check;

  printf("Please type the string: ");
  gets(str);

  printf("Please type the character you want to search for: ");
  scanf("%c", &op);

  check = sequential(str, strlen(str), op);

  if(check==-1)
  {
    printf("Cannot find one.");
  }
  else
  {
    printf("The index number: %d", check+1);
  }

  return 0;
}

int sequential(char *item, int length, char key)
{
  for(int i = 0; i< length; i++)
  {
    if (item[i] == key)
    {
      return i;
    }
  }
  return -1;
}
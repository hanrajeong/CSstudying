#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *str = (char*)malloc(sizeof(char)*100);

  printf("please type your name: ");
  scanf("%s", str);

  str[0] = 'J';

  printf("Your name is %s", str);

  free(str);

  return 0;
}
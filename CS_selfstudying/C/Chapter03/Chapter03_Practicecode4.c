#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char ch;

  printf("Please type one alphabet: ");
  scanf("%c", &ch);

  printf("input alphet: %c\n", ch);
  printf("Ascii code for the given alphabet: %d\n", ch);
  printf("The 8th alphabet from given one: %c\n", (int)ch+8);
  printf("The end");
}

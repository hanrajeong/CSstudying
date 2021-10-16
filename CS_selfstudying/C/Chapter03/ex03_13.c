#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  system("title Array and the Stringa");

  char ch;
  char str[10];

  printf("1.Please type the character: ");
  scanf("%c", &ch, sizeof(ch));

  printf("2.Please type the string: ");
  scanf("%s", &str, sizeof(str));

  printf("The input character is %c\n", ch);
  printf("The input string is %s\n", str);

  return 0;

}
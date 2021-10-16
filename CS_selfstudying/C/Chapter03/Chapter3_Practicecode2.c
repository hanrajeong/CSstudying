#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char op;
  char str[12];

  printf("1.Character: ");
  scanf("%c", &op);

  printf("2.String: ");
  scanf("%s", &str);

  printf("Character is %c\n", op);
  printf("String: |%s\t|", str);
}
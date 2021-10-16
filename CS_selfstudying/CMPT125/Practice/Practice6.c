#include <stdio.h>
#include <string.h>

int main(void)
{
  char *str = "Hello";
  char str_list[6] = {'H', 'e', 'l', 'l', '!'};
  char *s1;

  strcpy(s1, str);

  printf("%s\n", s1);

  s1[0] = 'C';

  printf("%s\n", s1);
  printf("%s\n", str);
  // printf("%c", str[0]);

  // str[0] = 'N';
  // length = strlen(str);
  // str_list[4] = '?';

  // printf("%s\n", str_list);
  // printf("%d", length);

  int length = strlen(str_list);

  printf("%d", length);

  return 0;
}
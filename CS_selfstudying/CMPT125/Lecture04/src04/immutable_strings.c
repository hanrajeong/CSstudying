#include <stdio.h>

int main(void) {
  char* str1 = "hello word";
  char* str2 = "hello word";
  char* str3 = "word";

  if (str1 == str2)
    printf("same pointer\n");
  else
    printf("different pointers\n");

  if (str3 == str2+6) // skipping "hello " in str2
    printf("same pointer\n");
  else
    printf("different pointers\n");

  return 0;
}
#include <stdio.h>

int main(void)
{
  const char c = 'a';

  char* ptr_char = &c;

  printf("%c", *ptr_char);
}
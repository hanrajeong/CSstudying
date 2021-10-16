#include <stdio.h>

void foo(char x) {
  x = 'b';
}

int main() {
  const char ch = 'a';
  foo(ch);
  printf("ch = %c", ch);
  return 0;
}
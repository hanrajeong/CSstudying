#include <stdio.h>

void creed(char **ppc);
void target(char **ppc);

int main(void)
{
  char *pc;

  creed(&pc);
  printf("%s", pc);
}

void creed(char **ppc)
{
  *ppc = "Hello";
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char* a;
  char* b;
  printf("please type two integers: ");
  scanf("%s %s", a, b);
  int a1 = atoi(a);
  int b1 = atoi(b);
  printf("%d\n", a1);
  printf("%d", b1);
  return 0;
}
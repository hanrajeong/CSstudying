#include <stdio.h>

void foun(void);
int main(void)
{
  int a;
  for (a=0; a<10; a+=3)
  {
    foun();
  }
  return 0;
}

void foun(void)
{
  int n;
  for(n=0; n<20; n+=3)
  {
    printf("A");
  }
  printf("\n");
}
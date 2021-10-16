#include <stdio.h>

int main(void)
{
  char c;
  char *pc;
  pc = &c;

  int i;
  int *pi;
  pi = &i;

  double d;
  double *pd;
  pd = &d;

  printf("the adress of pc: %d\n", pc);
  printf("the adress of pi: %d\n", pi);
  printf("the adress of pd: %d\n", pd);

  // printf("the value of pc: %d\n", *pc);
  // printf("the value of pi: %d\n", *pi);
  // printf("the value of pd: %d\n", *pd);

  *pc++;
  *pd++;
  *pi++;

  printf("the adress of pc: %d\n", pc);
  printf("the adress of pi: %d\n", pi);
  printf("the adress of pd: %d\n", pd);

  // printf("the value of pc: %d\n", *pc);
  // printf("the value of pi: %d\n", *pi);
  // printf("the value of pd: %d\n", *pd);

  return 0;
}
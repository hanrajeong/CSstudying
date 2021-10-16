#include <stdio.h>

void err_msg(void);
int main(void)
{
  err_msg(3);
  return 0;
}

void err_msg(void)
{
  printf("오류 발생\n");
}
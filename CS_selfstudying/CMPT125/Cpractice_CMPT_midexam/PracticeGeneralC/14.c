#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_memory(int n)
{
  int mem[32] = {0, };
  int i = 0;
  while(n>0)
  {
    mem[31-i] = n%2;
    n = n/2;
    i++;
  }
  for(i = 0; i<32; i++)
  {
    printf("%d", mem[i]);
  }
}

int main(void)
{
  check_memory(10);
}
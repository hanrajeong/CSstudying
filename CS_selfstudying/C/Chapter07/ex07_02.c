#include <stdio.h>

int main(void)
{
  int count;

  for(count = 1; count <= 10; count++)
  {
    printf("%02d : Hello\n", count);
  }

  return 0;

}
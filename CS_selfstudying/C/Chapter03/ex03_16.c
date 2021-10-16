#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  system ("title print Capital letter of alphabet with for");

  int cnt;

  printf("Capital Letter of Alphabet.\n");

  for (cnt = 65; cnt <= 90; cnt++)
    printf(" %c", cnt, sizeof(cnt));

  int a = 127;
  printf(" %c", a);
  return 0;

}
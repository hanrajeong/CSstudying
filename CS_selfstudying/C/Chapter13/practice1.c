#include <stdio.h>

int main(void)
{
  int count;
  char dept[5][8] = {"Seoul", "Busan", "Daegu", "Gwangju", "Jeju"};
  for(count = 0; count < 5; count++)
  {
    printf("%c area : %s\n", (65+count), dept[count]);
  }
  return 0;
}
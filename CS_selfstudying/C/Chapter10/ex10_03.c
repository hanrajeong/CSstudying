#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int num[7];
  int i = 0;

  printf("Let's print the random number between 1 to 500\n");

  srand((unsigned)time(NULL));

  for(; i < 7; i++)
  {
    num[i] = 1 + (rand() % 500);
  }

  for(int j = 0; j < 7; j++)
  {
    printf("num[%d] = %d\n", j, num[j]);
  }
  return 0;
}
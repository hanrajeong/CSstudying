#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 45

int main(void)
{
  int count;

  printf("Random number between 1 - 45\n");

  srand((unsigned)time(NULL));

  printf("Random number: ");
  for (count = 1; count <= 6; count++)
  {
    printf("%d ", 1 + (rand() % NUM));
  }

  printf("\n");

  return 0;
}
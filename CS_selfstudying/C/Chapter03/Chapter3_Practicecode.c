#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int K, E, M;

  printf("1. Korean: ");
  scanf("%d", &K);

  getchar();
  printf("2. English: ");
  scanf("%d", &E);

  getchar();
  printf("3. Maths: ");
  scanf("%d", &M);

  int total;
  float average;

  total = K + E + M;
  average = total / 3.0;

  printf("Total is %d\n", total);
  printf("Average is %.2f", average);

}
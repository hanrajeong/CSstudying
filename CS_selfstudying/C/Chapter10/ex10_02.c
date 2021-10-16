#include <stdio.h>

int main(void)
{
  int score[3];
  int total = 0;
  float avg = 0.0;

  for(int i = 0; i < 3; i++)
  {
    printf("please type the score of test%d: ", i+1);
    scanf("%d", &score[i]);
  }

  for(int j = 0; j < 3; j++)
  {
    total += score[j];
  }

  avg = (float)total / 3;

  printf("The total score is %d\n", total);
  printf("The average is %4.2f", avg);

  return 0;
}
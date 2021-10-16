#include <stdio.h>

int total_score(int score[], int size);

int main(void)
{
  int score[5] = {88, 96, 75, 81, 99};
  int sum = 0;
  double avg;

  sum = total_score(score, 5);
  avg = sum / 5;

  printf("The sum and  the average is %d %5.2f", sum, avg);

  return 0;
}

int total_score(int score[], int size)
{
  int total = 0;

  for(int i = 0; i<size; i++)
  {
    total += score[i];
  }

  return total;
}
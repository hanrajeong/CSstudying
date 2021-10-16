#include <stdio.h>

int main(void)
{
  char person_id[20];
  int scores[2][4] = {{0}};
  double avg[2] = {0,0};
  int total[2] = {0};

  for(int i = 0; i<2; i++)
  {
    printf("Please type your name: ");
    scanf("%s", &person_id, sizeof(person_id));

    for(int j = 1; j<4; j++)
    {
      printf("Subject%d score: ", j);
      scanf("%d", &scores[i][j]);
      total[i] += scores[i][j];
    }

    printf("\n");

    avg[i] = total[i] / 3.0;

    printf("%s's total scores is %d\n", person_id, total[i]);
    printf("%s's average score is %4.2f\n", person_id, avg[i]);
    printf("\n");
  }

  
  return 0;
}
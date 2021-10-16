#include <stdio.h>

int main(void)
{
  int score;

  printf("please enter your score: ");
  scanf("%d", &score);

  if(score>100 || score<0)
  {
    printf("Invalid Score");
  }
  else
  {
    if(score >= 90)
    {
      printf("you are 'A'");
    }
    else if(score >= 80)
    {
      printf("you are 'B'");
    }
    else if(score >= 70)
    {
      printf("you are 'C'");
    }
    else if(score >= 60)
    {
      printf("you are 'D'");
    }
    else
    {
      printf("you are 'F'");
    }
  }
  return 0;
}
  

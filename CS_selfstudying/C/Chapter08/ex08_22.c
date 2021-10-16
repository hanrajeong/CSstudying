#include <stdio.h>
#include <stdlib.h>

void score(); //중간 기말 점수를 입력받음
char grade(int jumsu); //입력한 점수의 등급을 계산
void alp_error(char alpha); // Y, N 외의 알파벳이 입력되면 메시지 출력
void score_error(int jumsu); // 0~100 이외의 숫자가 입력되면 메시지 출력
void end_score(char alph); // main()함수에서 N 값 입력받으면 종료

void main()
{
  char choice;
  int input_score;
  
  while(1)
  {
    char choice;

    printf("Do you want to start the program? (Y/N) ");
    scanf("%c", &choice, sizeof(choice));

    if(choice == 'Y' || choice == 'y')
    {
      score();
      getchar();
      break;
    }
    else if(choice == 'N' || choice == 'n')
    {
      end_score(choice);
      getchar();
      break;
    }
    else
    {
      alp_error(choice);
      getchar();
      break;
    }
  }
}

void score()
{
  int input_score1, input_score2;
  int totalscore = 0;

  printf("can you please enter your mid-term score? ");
  scanf("%d", &input_score1);

  if(input_score1 < 0 || input_score1 > 50)
  {
    score_error(input_score1);
  }
  else
  {
    totalscore += input_score1;
  }
  printf("can you please enter your final exam score? ");
  scanf("%d", &input_score2);

  if(input_score2 < 0 || input_score2 > 50)
  {
    score_error(input_score2);
  }
  else
  {
    totalscore += input_score2;
    grade(totalscore);
    getchar();
  }
  main();
  
}

char grade(int jumsu)
{
  return printf("your grade is 'A'\n");
}

void alp_error(char alpha)
{
  printf("Invalid input\n");
  getchar();
  main();
}

void score_error(int jumsu)
{
  printf("Invalid score input\n");
  score();
}

void end_score(char alph)
{
  printf("System will be closed\n");
  exit(0);
}

#include <stdio.h>

int person1(void);

int main(void)
{
  int tic[3][3] = {' '};
  char tic1[3][3] = {' '};
  int i, j;
  int count;

  for(int p =0; p<9; p++)
  {
  re_play:
    printf("%d input(type the index i, j, both are between 0 and 2): ", p+1);
    scanf("%d %d", &i, &j);

    if(i<0 || i>2 || j<0 || j>2)
    {
      printf("Error!!!\n");
      printf("Please retype the value\n");
      goto re_play;
    }
    if(p%2 == 0)
    {
      tic[i][j] = '0';
      tic1[i][j] = 'O';
    }
    else
    {
      tic[i][j] = '1';
      tic1[i][j] = 'X';
    }
  }
  // printf("%c\n", tic1[0][0]);
  // printf("%c\n", tic1[0][1]);
  // printf("%c\n", tic1[0][2]);
  // printf("%c\n", tic1[1][0]);
  // printf("%c\n", tic1[1][1]);
  // printf("%c\n", tic1[1][2]);
  // printf("%c\n", tic1[2][0]);
  // printf("%c\n", tic1[2][1]);
  // printf("%c\n", tic1[2][2]);

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("%c", tic1[i][j]);
    }
    printf("\n");
  }

  
}
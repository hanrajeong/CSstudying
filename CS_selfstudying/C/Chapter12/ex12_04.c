#include <stdio.h>

int main(void)
{
  int a[2][4] = 
  {
    {10, 20, 30, 0},
    {40, 50, 60 ,0}
  };

  int(*four)[4];
  int row, col;

  four = a;

  for(row=0; row<2; row++)
  {
    for(col=0; col<3; col++)
    {
      four[row][3] += four[row][col];
    }
  }

  for(row = 0; row<2; row++)
  {
    printf("The total of the elements for %d rows : %d\n", row+1, four[row][3]);
  }

  return 0;
}
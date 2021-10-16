#include <stdio.h>

int main(void)
{
  int count = 1;

  while(count <= 5)
  {
    int space = 1;
    while(space <= 5)
    {
      if(space == count)
      {
        if(count%2 == 1)
        {
          printf("| O |");
        }
        else
        {
          printf("| X |");
        }
      }
      else
      {
        printf("   ");
      }
    space++;
    }
      printf("\n");
      printf("-----------------\n");
      count++;
  }
}
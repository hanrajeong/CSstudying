#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int size;

  scanf("%d", &size);

  int **mat = malloc(sizeof(int *) * size);

  for(int i = 0; i < size; i++)
  {
    mat[i] = malloc(sizeof(int) * size);
  }

  for(int p = 0; p < size; p++)
  {
    for(int j = 0; j < size; j++)
    {
      if(p == j)
      {
        mat[p][j] = 1;
        printf("%d ", mat[p][j]);
      }
      else
      {
        mat[p][j] = 0;
        printf("%d ", mat[p][j]);
      }
    }
    printf("\n");
  }
}
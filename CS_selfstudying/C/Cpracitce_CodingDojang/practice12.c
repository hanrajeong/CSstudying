// 5 5
// *....
// .*.**
// .*...
// .....
// .....

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int m, n;

  scanf("%d %d", &m, &n);

  char **mat = malloc(sizeof(char *) * m);
  int **mat2 = malloc(sizeof(int *) * m);

  for(int k = 0; k < m; k++)
  {
    mat[k] = malloc(sizeof(char) * (n+1));
    mat2[k] = malloc(sizeof(int) * n);
  }

  for(int i = 0; i < m; i++)
  {
    scanf("%s", mat[i]);
  }

  for(int a = 0; a < m; a++)
  {
    for(int b = 0; b < n; b++)
    {
      if(mat[a][b] == '*')
      {
        mat2[a][b] = 1;
      }
      else
      {
        mat2[a][b] = 0;
      }
    }
  }

  for(int a = 0; a < m; a++)
  {
    for(int b = 0; b < n; b++)
    {
      if(mat[a][b] == '*')
      {
        printf("%c", mat[a][b]);
      }
      else
      {
        int sum = 0;
        for(int c = a-1; c < a+2; c++)
        {
          for(int d = b-1; d < b+2; d++)
          {
            if(c < 0 | c >= m | d < 0 | d >= n)
            {
              continue;
            }
            sum += mat2[c][d];
          }
        }
        printf("%d", sum);
      }
    }
    printf("\n");
  }

  return 0;
}


#include <stdio.h>
#include <stdbool.h>

bool contains_eqaul_rows(int height, int width, const int array[height][width])
{
  bool flag = false;
  for(int i = 0; i < height; i++)
  {
    for(int j = i+1; j < height; j++)
    {
      for(int k = 0; k < width; k++)
      {
        if(array[i][k]==array[j][k])
          flag = true;
        else
        {
          flag = false;
          break;
        }
      }
      if(flag==true)
        return true;
    }
  }
  return flag;
}

int main(void)
{
  int array[3][3] = {{1, 2, 3}, {2, 3, 4}, {1, 2, 3}};
  printf(contains_eqaul_rows(3, 3, array) ? "true" : "false");
}
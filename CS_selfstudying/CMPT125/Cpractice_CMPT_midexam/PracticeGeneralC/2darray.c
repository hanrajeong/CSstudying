#include <stdio.h>
#include <stdbool.h>

bool contains_equal_rows(int height, int width, const int array[height][width])
{
  bool flag = false;
  for(int h = 0; h < height; h++)
  {
    for(int k = h+1; k < height; k++)
    {
      for(int w = 0; w<width; w++)
      {
        if(array[h][w]!=array[k][w])
        {
          flag = false;
          break;
        }
        else
        {
          flag = true;
        }
      }
      if(flag == true)
      {
        return true;
      }
    }
  }
  return false;
}

int main(void)
{
  int array[3][3] = {{1, 2, 3}, {2, 3, 4}, {1, 5, 3}};
  int height = 3;
  int width = 3;

  printf(contains_equal_rows(height, width, array) ? "true" : "false");

  return 0;
}
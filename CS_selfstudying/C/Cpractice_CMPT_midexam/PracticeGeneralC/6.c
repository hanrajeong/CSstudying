#include <stdio.h>
#include <stdbool.h>

bool contains_equal_rows(int height, int width, const int array[height][width])
{
  bool result = false;

  for(int i = 0; i <height-1; i++)
  {
    for(int j = i+1; j < height; j++)
    {
      for(int k = 0; k < width; k++)
      {
        printf("array[%d][%d] == array[%d][%d]\n", i, k, j, k);
        if(array[i][k] == array[j][k])
        {
          result = true;
        }
        else
        {
          result = false;
        }
      }
      if(result == true)
      {
        return result;
      }
    }
  }
  return result;
}

int main(void)
{
  int arr[3][3] = {{1, 2, 6}, {1, 4, 7}, {1, 4, 7}};
  int height = 3;
  int width = 3;

  bool result = contains_equal_rows(height, width, arr);
  printf(result ? "true" : "false");  


  return 0;
}
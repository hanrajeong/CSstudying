#include <stdio.h>

int main()
{
    int a[3][4] = {
        {0, 1, 2, 3} ,   //  initializers for 0 row
        {4, 5, 6, 7} ,   //  initializers for 1 row
        {8, 9, 10, 11}   //  initializers for 2 row
    };

    int b[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    printf("size of arry is %d\n", sizeof(*b));

    int (*ptr)[4] = a;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    printf("size of array pointer is %d\n", sizeof(*ptr));

    int col = sizeof(a[0])/sizeof(int);
    int row = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < row; i++)
    {
      int c = 0;
      for (int j = 0; j < col; j++)
      {
        
        if(a[i][j] != b[i][j])
        {
          break;
        }
        else
        {
          c++;
        }
        if(c==3)
        {
          printf("for row[%d], they are same\n", i);
        }
        
      }
    }
    return 0;
}

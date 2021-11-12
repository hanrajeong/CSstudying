#include <stdio.h>

void print_2d_array(int height, int width, int array[height][width])
{
    int i,j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%3d ", array[i][j]);
            // alt: printf("%d ", (*(array+i))[j]);
            // alt2: printf("%d ", *(*(array+i)+j));
        }
        printf("\n");
    }

}


int main()
{
    int a[4][4] = {
        {0, 1, 2, 3} ,   //  initializers for 0 row
        {4, 5, 6, 7} ,   //  initializers for 1 row
        {8, 9, 10, 11},
        {8, 9, 10, 11}    //  initializers for 2 row
    };


    printf("a:\n");
    print_2d_array(3, 4, a);
    printf("\n");

    int b[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};


    printf("b:\n");
    print_2d_array(3, 4, b);
    printf("\n");

    printf("size of *a = %ld\n", sizeof(*a));

    printf("%d\n", b);
    printf("%d\n", *(b+1));
    printf("%d\n", *(*(b+1)+1));

// more subtelties
// this is ok
    int c[][4] = {
        {0, 1, 2, 3} ,   //  initializers for 0 row
        {4, 5, 6, 7} ,   //  initializers for 1 row
        {8, 9, 10, 11}   //  initializers for 2 row
    };

// this does not compile
//    int c[][] = {
//        {0, 1, 2, 3} ,   //  initializers for 0 row
//        {4, 5, 6, 7} ,   //  initializers for 1 row
//        {8, 9, 10, 11}   //  initializers for 2 row
//    };

    return 0;
}

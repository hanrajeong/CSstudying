#include <stdio.h>

void swap (int* a, int* b)
{
    printf("Address of *a = %p\n", a);
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void swap_wrong (int a, int b)
{
    printf("Address of a = %p\n", &a);
    int tmp = a;
    a = b;
    b = tmp;

}


int main()
{
    int x = 5;
    int y = 7;
    printf("x = %d, y = %d\n", x, y );

    printf("Address of x = %p\n", &x);
    swap(&x,&y);
//    swap_wrong(x,y);
    printf("x = %d, y = %d\n", x, y );

    return 0;
}

#include <stdio.h>

int main()
{
    int x = 5; // variable x has value 5
    printf("x = %d\n", x); // x = 5

    printf("----------\n"); // -----------

    int* px = &x; // pointer to the location of x
    printf("The value at the address %p is %d\n", px, *px); // The value at the address () is 5

    printf("----------\n"); // -----------

    *px = 7; // dereferencing, changing the value at the address px
    printf("x = %d\n", x); // 7
    printf("px = %p\n", px); // adress of x
    printf("*px = %d\n", *px); // 7

    return 0;
} 
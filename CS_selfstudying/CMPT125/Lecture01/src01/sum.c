#include <stdio.h>

int main()
{
    int x = 5;
    int y = 10;
    printf("The sum of %d and %d is %d\n", x, y, x+y); // The sum of 5 and 10 is 15

    long z = 9876543210;
    printf("printing long z = %ld\n", z); // printing long z = 9876543210

    int w = 9876543210; // assigned value is too large for int
    printf("printing int w = %d\n", w);  // printing int w = 9876543210

    return 0;
}

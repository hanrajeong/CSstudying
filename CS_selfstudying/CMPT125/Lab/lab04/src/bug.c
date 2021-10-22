#include <stdio.h>

void fun1() {
    float x = 0.0;

    while (x < 1.0000000000000000001) {
        printf("x = %f\n", x);
        x = x + 0.1;
    }
    printf("the final value of x = %f\n", x); 
    // why x = 1.0000 not printed?
}

void fun2() {
    double y = 1.0;
    while (y < 1.99999999999999999999) {
        printf("y = %lf\n", y);
        y = y + 0.2;
    }
    printf("the final value of y = %lf\n", y);
    // why y = 2.0000 was printed?
}

int main () {
    fun1();
    fun2();
}
  
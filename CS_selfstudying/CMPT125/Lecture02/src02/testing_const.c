#include <stdio.h>

/* Testing the modifier const */



int main()
{
    char c = 'A';
    const char c1 = 'a'; // const must be initialized
    char const c2 = 'b'; // both 'const char' and 'char const' are allowed
//    c1 = 'c'; // not allowed
//    c2 = 'b'; // cannot change even to the same value


    char* ptr1;

    ptr1 = &c; // ok, since c is not const
    printf("%c\n", *ptr1);


    const char* ptr2 = &c1; // pointer to 'const char'. Ok to assign &c1
    ptr2 = &c2; // ok
    ptr2 = &c; // also ok (ptr will not be allowed to change the data)
//    *ptr2 = 'R'; // not allowed
    c = 'R'; // ok


//    char* ptr3 = &c1; //  DANGEROUS! Warning from the compiler: cannot assign &c1
//    *ptr3 = 'T'; // DANGEROUS! Crash at runtime
//    printf("%c", c1);


    char* const ptr4 = &c; // const_ptr must be initialized
    *ptr4 = 'D'; // ok
    printf("*ptr4 = %c\n", *ptr4);
    char e = 'E';
//    ptr4 = &e; // cannot reassign constant pointer


    const char* const ptr3 = &c1;;
//    ptr3 = &c2; // cannot reassign constant pointer
    // ptr3 = 5;

    return 0;
}

/* Testing the chars  */

#include <stdio.h>


int main()
{
    char ch = 'A';
    printf("The char value of ch = %c\n", ch);
    printf("The numerical value of ch = %d\n", ch);

    printf("\n\n---increasing ch by 3---\n");
    ch = ch+3;
    printf("The char value of ch is now %c\n", ch);
    printf("The numerical value of ch is now %d\n", ch);

    printf("The char with numerical value 67 is %c\n", 67);

    printf("The char with numerical value 64 is %c\n", 64);

    char c = 64;
    printf("\n\n c = %c\n", c);

    return 0;
}

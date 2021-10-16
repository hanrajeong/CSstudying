#include <stdio.h>

int main(void)
{
    int num1;
    
    scanf("%d", &num1);

    while(num1  > 0)
    {
        int r = num1 % 10;
        num1 /= 10;
        printf("%d ", r);
    }
    
    
    return 0;
}
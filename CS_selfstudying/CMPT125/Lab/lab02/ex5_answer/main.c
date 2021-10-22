#include <stdio.h>
#include "minmax.h"

int main()
{
    int a=10;
    int b =20;
    int c=25;
    int min_number, max_number;
    min_number=min(a,b,c);
    max_number=max(a,b,c);
    
    printf("Min number is %d and Max number is %d\n", min_number,max_number);
    
}


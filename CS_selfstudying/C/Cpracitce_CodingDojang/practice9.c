#include <stdio.h>

int main()
{
    int numArr[5];
    int smallestNumber;

    scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);

    smallestNumber = numArr[0];

    for(int i = 1; i < (sizeof(numArr)/sizeof(int)); i++)
    {
        if(numArr[i] < smallestNumber)
        {
            smallestNumber = numArr[i];
        }
    }

    printf("%d\n", smallestNumber);

    return 0;
}
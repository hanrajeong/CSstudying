#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    int *numPtr;    // 4바이트만큼 메모리 할당
    int num1 = 10;

    numPtr = &num1;

    printf("%d\n", *numPtr);    // 0x78: numPtr1을 char 포인터로 변환한 뒤 역참조
    printf("%p\n", numPtr);

    return 0;
}
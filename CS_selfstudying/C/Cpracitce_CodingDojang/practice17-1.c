#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *s1 = malloc(sizeof(char) * 1001); // 크기가 30인 char형 배열을 선언하고 문자열 할당
    scanf("%[^\n]s", s1);
    int count = 0;

    char *ptr = strchr(s1, ' ');     // 'a'로 시작하는 문자열 검색, 포인터 반환

    while (ptr != NULL)              // 검색된 문자열이 없을 때까지 반복
    {
        count++;      
        ptr = strchr(ptr + 1, ' ');  // 포인터에 1을 더하여 a 다음부터 검색
    }

    printf("%d", count);

    return 0;
}
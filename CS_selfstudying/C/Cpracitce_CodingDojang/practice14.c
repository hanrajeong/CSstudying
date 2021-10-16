#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[31];
    char s2[31];
    
    scanf("%s %s", s1, s2);
    
    int ret =  strcmp(s1, s2);
    
    if (ret == 0)
    {
        printf("0\n");
    }
    else if (ret > 0)    // 양수일 때
    {
        printf("1\n");
    }
    else if (ret < 0)    // 음수일 때
    {
        printf("-1\n");
    }

    return 0;
}
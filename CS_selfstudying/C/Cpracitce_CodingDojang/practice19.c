#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[61];
    char *s2[61] = {NULL, };
    
    scanf("%s", s1);
    
    char *ptr = strtok(s1, ".");
    
    while(ptr!=NULL)
    {
        for(int i = 0; i < 30; i++)
        {
            s2[i] = ptr;
            printf("%s\n", s2[i]);
            i++;
            ptr = strtok(NULL, ".");
        }
    }
    
    return 0;
    
}
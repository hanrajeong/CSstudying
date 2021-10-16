#include <stdio.h>
#include <string.h>

int main(void)
{
    int count = 0;
    char str[1001];
    
    scanf("%[^\n]s", str);
    
    char* ptr = strtok(str, " .,");
    
    while(ptr != NULL)
    {
        if(strcmp(ptr, "the") == 0)
        {
          count++;
        }
        ptr = strtok(NULL, " .,");
    }
    
    printf("%d", count);
}
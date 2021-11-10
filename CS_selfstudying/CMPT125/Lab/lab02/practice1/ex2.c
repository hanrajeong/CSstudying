#include <stdio.h>

int main()
{
  int array[10];
  for(int c = 0; c<10; c++)
  {
    printf("enter the number: ");
    scanf("%d", &array[c]);
  }

  for(int i = 0; i<10; i++)
  {
    array[i]++;
  }

  for(int c = 0; c<10; c++)
    printf("%d ", array[c]);

  return 0;
}
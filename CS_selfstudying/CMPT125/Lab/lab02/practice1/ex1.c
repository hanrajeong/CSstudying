#include <stdio.h>

int main()
{
  int array[10];
  for(int c = 0; c<10; c++)
  {
    printf("enter the number: ");
    scanf("%d", &array[c]);
  }

  int max = array[0];
  for(int i = 1; i < 10; i++)
  {
    if(max<array[i])
      max=array[i];
  }
  printf("the maximum element is %d", max);

  return 0;
}
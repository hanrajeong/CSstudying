#include <stdio.h>

int main(void)
{
  int score[] = {87, 92, 89, 98, 78};
  
  for(int i = 0; i<5; i++)
  {
    printf("score[%d] = [%d]\n", i, score[i]);
  }
  return 0;
}
#include <stdio.h>

int main(void)
{
  double avg[3] = {0.0};
  int total[3] = {0};
  int bd[3][5] =
  {
    {125, 150, 148, 160, 153},
    {115, 120, 123, 121, 112},
    {132, 129, 128, 133, 130}
  };

  for(int i = 0; i<3; i++)
  {
    for(int j =0; j<5; j++)
    {
      total[i] += bd[i][j];
    }
  }
  for(int k = 0; k<3; k++)
  {
    avg[k] = total[k] / 5;
  }

  for(int p = 0; p<3; p++)
  {
    if(avg[p]>140)
    {
      printf("Person%d : %f, High BP\n", p, avg[p]);
    }
    else
    {
      printf("Person%d : %f, Normal BP\n", p, avg[p]);
    }
  }
  
  

  return 0;
}


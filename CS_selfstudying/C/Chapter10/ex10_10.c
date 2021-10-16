#include <stdio.h>

int main(void)
{
  int nums[5] = {5, 4, 3, 2, 1};
  int a, b, temp, sort;

  for(a=0; a<4; a++)
  {
    sort = a;

    for(b=a+1; b<5; b++)
    {
      if(nums[b] < nums[sort])
        sort = b;
    }
    temp = nums[a];
    nums[a] = nums[sort];
    nums[sort] = temp;
  }

  for (int j = 0; j<5; j++)
  {
    printf("%d", nums[j]);
  }

  printf("\n");

  return 0;
}
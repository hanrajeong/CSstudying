#include <stdio.h>

int b_s(int list[], int n, int input);

int main(void)
{
  int nums[8] = {3, 8, 15, 24, 35,37, 68, 85};
  int input;
  int search;
  char op;

  while(1)
  {
    printf("Please type the integers that you want to find: ");
    scanf("%d", &input);

    search = b_s(nums, 8, input);
    printf("The index of your required number is %d\n", search);

attempt:

    printf("Do you want to try again?");
    scanf("%c", &op, sizeof(op));

    if(op=='Y' || op== 'y')
    {
      continue;
    }
    else if(op=='n' || op=='N')
    {
      break;
    }
    else
    {
      printf("Please type only y or n\n");
      printf("Please retype: ");
      goto attempt;
    }
  }

  return 0;
}

int  b_s(int list[], int n, int input)
{
  int low = 0;
  int high = n-1;
  int md = 1;

  while(low<=high)
  {
    md = (low + high)/2;

    if(input == list[md])
    {
      return md;
    }
    else if(input > list[md])
    {
      low = md+1;
    }
    else
    {
      high = md -1;
    }
  }
  return -1;
}
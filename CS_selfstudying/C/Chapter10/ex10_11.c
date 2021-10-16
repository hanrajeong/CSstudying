//순차 탐색 문제

#include <stdio.h>

int main(void)
{
  int nums[7] = {5, 4, 1, 3, 2, 7, 6};
  int input;
  char op;

  while(1)
  {
    printf("Please type the number you want to find: ");
    scanf("%d", &input);

    if(input > 7 || input < 1)
  {
    printf("please type the number again. Number should between 1 to 7!");
    printf("Please retype the number: ");
    continue;
  }

    for(int i = 0; i<7; i++)
    {
      if(nums[i]==input)
      {
        printf("순차 탐색 횟수: %d", i+1);
        printf("The index: %d\n", i);
      }
    }

  again:

    printf("Should we try the program again?");
    scanf("%c", &op, sizeof(op));

    if(op=='y' || op=='Y')
    {
      continue;
    }
    else if(op=='N' || op=='n')
    {
      break;
    }
    else
    {
      printf("please type only y/n\n");
      printf("please retype: ");
      goto again;
    }
  }
  return 0;
  
}
#include <stdio.h>

int main(void)
{
  int input_number;

  printf("please enter the integers: ");
  scanf("%d", &input_number);

  if(input_number%2 == 0)
  {
    printf("This is even number");
  }
  else
  {
    printf("This is odd number");
  }
}
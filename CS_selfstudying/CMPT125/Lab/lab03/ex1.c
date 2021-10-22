#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// write a function that recive two integers as main function arguments and return sum of them

int main(int arg, char* argv[])
{
  printf("what is in argv[0]?");
  scanf("%s", argv[0]);
  printf("what is in argv[1]?");
  scanf("%s", argv[1]);

  int sum = atoi(argv[1]) + atoi(argv[0]);

  printf("First number %d + Second number %d = %d", argv[0], argv[1], sum);

  return sum;
}
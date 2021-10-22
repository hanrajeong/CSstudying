#include <stdio.h>

// a program that get an integer in decimal and print its binary form

int main(void)
{
  int num;
  int i = 0;
  int bi[100] = {0, };
  printf("please type the decimal number: ");
  scanf("%d", &num);

  while(num!=0)
  {
    bi[i] = num%2;
    num = num/2;
    i++;
  }

  for(int j = i-1; j>=0; j--)
  {
    printf("%d", bi[j]);
  }

  return 0;
}
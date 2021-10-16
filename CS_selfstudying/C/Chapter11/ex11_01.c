#include <stdio.h>

int main(void)
{
  int i_num = 3;
  char ch = 'A';
  float f_num = 21.5;

  printf("print the adress: \n");
  printf("1. int: %u\n", &i_num);
  printf("2. char: %u\n", &ch);
  printf("3. f_num: %u\n", &f_num);
  printf("3. f_num: %d", &f_num);
}
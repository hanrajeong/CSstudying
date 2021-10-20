#include <stdio.h>

int binary_to_int(const char* binary)
{
  int result = 0;
  int size = 0;
  int i = 0;
  while(binary[i] != '\0')
  {
    size++;
    i++;
  }
  for(int j =0; j < size; j++)
  {
    int bi = 1;
    for(int k = 1; k<=j; k++)
    {
      bi = bi*2;
    }
    if(binary[j] == '1')
    {
      result += bi;
    }
  }
  return result;
}

int main(void)
{
  char *binary = "11011";

  printf("%d", binary_to_int(binary));

  return 0;
}
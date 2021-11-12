#include <stdio.h>
#include <string.h>

int binary_to_int(const char* binary)
{
  int len = strlen(binary);
  int two = 1;
  int ret = 0;
  for(int i = len-1; i>=0; i--)
  {
    if(binary[i] == '1')
    {
      ret = ret + two;
    }
    two = two*2;
  }
  return ret;
}

int main(void)
{
  char* bi = "11011";
  printf("%d ", binary_to_int(bi));
}
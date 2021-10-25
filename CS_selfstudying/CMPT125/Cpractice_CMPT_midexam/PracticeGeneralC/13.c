#include <stdio.h>
#include <string.h>

// int binary_to_int(const char* binary)
// {
//   int result = 0;
//   int size = 0;
//   int i = 0;
//   while(binary[i] != '\0')
//   {
//     size++;
//     i++;
//   }
//   for(int j =0; j < size; j++)
//   {
//     int bi = 1;
//     for(int k = 1; k<=j; k++)
//     {
//       bi = bi*2;
//     }
//     if(binary[j] == '1')
//     {
//       result += bi;
//     }
//   }
//   return result;
// }

int binary_to_int(const char* binary)
{
  int two = 1;
  int result = 0;
  int len = strlen(binary);
  if(binary[0] == '1')
  {
    result += 1;
  }
  for(int i = 1; i<len; i++)
  {
    two = two*2;
    if(binary[i] == '1')
    {
      result += two;
    }
  }
  return result;
}

// int binary_to_int(const char* binary)
// {
//   int two = 1;
//   int num = 0;
//   int len = strlen(binary);
//   for(int i = 0; i <len; i++)
//   {
//     if(binary[i] == '1')
//     {
//       num = num+two;
//     }
//     two = two*2;
//   }
//   return num;
// }

int main(void)
{
  char *binary = "11011";

  printf("%d", binary_to_int(binary));

  return 0;
}
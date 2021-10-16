#include <stdio.h>
#include <string.h>

int binary_search(char*, int, char);

int main(void)
{
  char str[80];
  int result;
  char op;

  printf("please type the string: ");
  gets(str);

  printf("please type the character you want to find: ");
  scanf("%c", &op);

  result = binary_search(str, strlen(str), op);

  if(result == -1)
  {
    printf("Cannot fine one\n");
  }
  else
  {
    printf("The index is %d", result+1);
  }

  return 0;
}

int binary_search(char *item, int length, char key)
{
  int start = 0, end = length - 1, mid;

  while(start<=end)
  {
    mid = (start + end) / 2;

    if(key == item[mid])
    {
      return mid;
    }
    else if(key > item[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid - 1;
    }
  }
  return -1;
}
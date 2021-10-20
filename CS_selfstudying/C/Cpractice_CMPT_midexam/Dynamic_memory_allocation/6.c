#include <stdio.h>

typedef struct{
  int* ar;
  int len;
} array_with_length;

int add_item(array_with_length* awl, int new_item)
{
  int **arr = awl->ar;
  int length = awl->len;
  arr[length] = new_item;
  length = length + 1;
  if (arr[length] == new_item)
  {
    return 1;
  }
  return -1;
}

int remove_last(array_with_length* awl)
{
  int **arr = awl->ar;
  int length = awl->len;
  int existed = arr[length-1];
  arr[length] = NULL;
  length = length - 1;

  return existed;
}

int main(void)
{
  int arr = (int*)(1000*sizeof(int));
  int length = 0;
  array_with_length *aw1 = {&arr, &length};


  add_item(aw1, 10);
  add_item(aw1, 20);
  add_item(aw1, 30);

  int final_len = aw1->len;
  int* arr_final = aw1->ar;
  for(int i = 0; i < length; i++)
  {
    printf("%d", arr_final[i]);
  }
}
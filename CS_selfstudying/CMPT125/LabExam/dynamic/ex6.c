#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* ar;
  int len;
} array_with_length;

array_with_length* create_empty_array()
{
  array_with_length* awl = (array_with_length*)malloc(sizeof(array_with_length));
  if(awl==NULL)
    return NULL;
  awl->len = 0;
  awl->ar = NULL;
  return awl;
}

int add_item(array_with_length* awl, int new_item)
{
  if(awl->len==0)
  {
    awl->ar = (int*)malloc(sizeof(int));
  }
  awl->ar[awl->len] = new_item;
  (awl->len)++;
  return new_item;
}

int remove_last(array_with_length* awl)
{
  int ret = awl->ar[(awl->len)-1];
  (awl->len)--;
  return ret;
}

int main(void)
{
  array_with_length* awl = create_empty_array();
  add_item(awl, 1);
  add_item(awl, 2);
  add_item(awl, 3);
  add_item(awl, 4);
  add_item(awl, 5);
  remove_last(awl);
  for(int i = 0; i < awl->len; i++)
  {
    printf("%d ", awl->ar[i]);
  }
}

#include <stdio.h>
#include <stdlib.h>
#define init 3

typedef struct{
  int* ar;
  int size;
  int head;
} stack_t;

int stack_is_empty(stack_t* s);

stack_t* create_stack()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
  {
    return NULL;
  }
  s->ar = (int*)malloc(sizeof(int)*init);
  if(s->ar == NULL)
  {
    return NULL;
  }
  s->size = init;
  s->head = 0;
}

int stack_push(stack_t* s, int item)
{
  if(s->head == s->size)
  {
    int* temp = (int*)realloc(s->ar, (s->size)*2*sizeof(int));
    if(temp==NULL)
    {
      return -1;
    }
    s->ar = temp;
    s->size = (s->size)*2;
  }
  (s->ar)[s->head] = item;
  (s->head)++;

  return item;
}

int stack_pop(stack_t* s)
{
  if(stack_is_empty(s))
  {
    return -1;
  }
  (s->head)--;
  return (s->ar)[s->head];
}

int stack_is_empty(stack_t* s)
{
  return ((s->head)==0);
}

int free_stack(stack_t* s)
{
  free(s->ar);
  free(s);
}


int main()
{
  stack_t* s = create_stack();
  if(s==NULL)
  {
    printf("could not creat stack\n");
  }

  stack_push(s, 1);
  stack_push(s, 2);
  stack_push(s, 3);
  stack_push(s, 4);
  printf("%d ", stack_pop(s));
  printf("%d ", stack_pop(s));
  printf("%d ", stack_pop(s));
  printf("%d ", stack_pop(s));
  printf("\n");
  printf("%d ", stack_is_empty(s));

  free_stack(s);
}

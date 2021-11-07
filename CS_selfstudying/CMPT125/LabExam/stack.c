#include <stdio.h>
#include <stdlib.h>

// STACK WITH FIXED CAPACITY

#define MAX_SIZE 100

typedef struct {
    int size;
    int* ar;
    int head;
} stack_t; 

int stack_is_empty(stack_t* s);

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if (s==NULL)
  {
    return NULL;
  }

  s->ar = (int*)malloc(MAX_SIZE*sizeof(int));
  if(s->ar == NULL)
  {
    return NULL;
  }

  s->size = MAX_SIZE;
  s->head = 0;
  return s;
}

void stack_push(stack_t* s, int item)
{
  (s->ar)[s->head] = item;
  (s->head)++;
}

int stack_pop(stack_t* s)
{
  if(stack_is_empty(s))
  {
    printf("stack is empty!");
    return -1;
  }

  (s->head)--;
  return (s->ar)[s->head];
}

int stack_is_empty(stack_t *s)

{
  return (s->head == 0);
}

void stack_free(stack_t *s)
{
  free(s->ar);
  free(s);
}

int main()
{
  stack_t* s = stack_create();
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

  stack_free(s);
}
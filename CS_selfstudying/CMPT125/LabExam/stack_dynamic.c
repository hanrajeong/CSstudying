#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 3

typedef struct{
  int capacity;
  int head;
  int* ar;
} stack_t;

int stack_isempty(stack_t* s);

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
  s->ar = (int*)malloc(INIT_CAPACITY*sizeof(int));
  if(s->ar == NULL)
    return NULL;
  s->capacity = INIT_CAPACITY;
  s->head = 0;
  return s;
}

int stack_push(stack_t* s, int item)
{
  if(s->head == s->capacity)
  {
    int* tmp_ar = (int*) realloc(s->ar, (s->capacity)*2*sizeof(int));

        // handling relloc failure
    if (tmp_ar == NULL)
      return -1;

    s->ar = tmp_ar;

    s->capacity = (s->capacity)*2;
  }
  (s->ar)[s->head] = item;
  (s->head)++;

  return item;
}

int stack_pop(stack_t* s)
{
  if(stack_isempty(s))
  {
    printf("STACK IS EMPTY!");
    return -1;
  }
  (s->head)--;
  return (s->ar)[s->head];
}

int stack_isempty(stack_t* s)
{
  return (s->head == 0);
}

void stack_free(stack_t*s)
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
  printf("%d ", stack_isempty(s));

  stack_free(s);
}

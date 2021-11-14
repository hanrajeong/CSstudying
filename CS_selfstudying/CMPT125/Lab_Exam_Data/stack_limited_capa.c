#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 10

typedef struct {
  int size;
  int* ar;
  int head;
} stack_t;

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
  s->size = maxsize;
  s->ar = (int*)malloc(maxsize*sizeof(int));
  s->head = 0;
  return s;
}

void stack_push(stack_t* s, int item)
{
  (s->ar)[s->head] = item;
  (s->head)++;
}

bool stack_is_empty(stack_t* s)
{
  return (s->head == 0);
}

int stack_pop(stack_t* s)
{
  if(stack_is_empty(s))
    return -1;
  (s->head)--;
  return (s->ar)[s->head];
}

void stack_free(stack_t* s)
{
  free(s->ar);
  free(s);
}


int main()
{
  stack_t* s = stack_create();
  if (s == NULL)
  {
    printf("could not create stack\n");
    return -1;
  }

  printf("stack push(%d)\n", 1);
  stack_push(s, 1); // s = [1]
  printf("stack push(%d)\n", 2);
  stack_push(s, 2); // s = [1,2]
  printf("stack push(%d)\n", 3);
  stack_push(s, 3); // s = [1,2,3]
  printf("stack push(%d)\n", 4);
  stack_push(s, 4); // s = [1,2,3,4]

  printf("stack pop = %d\n", stack_pop(s));  // s = [1,2,3] print 4

  printf("stack push(%d)\n", 5);
  stack_push(s, 5); // s = [1,2,3,5]

  printf("stack pop = %d\n", stack_pop(s));  // s = [1,2,3] print 5

  printf("stack push(%d)\n", 6);
  stack_push(s, 6); // s = [1,2,3,6]

  printf("stack pop = %d\n", stack_pop(s)); // s = [1,2,3] print 6
  printf("stack pop = %d\n", stack_pop(s)); // s = [1,2] print 3
  printf("stack pop = %d\n", stack_pop(s)); // s = [1] print 2

  if (stack_is_empty(s))
    printf("Stack is empty\n");
  else
    printf("Stack is not empty\n");

  printf("stack pop = %d\n", stack_pop(s)); // s = [] print 1

  if (stack_is_empty(s))
    printf("Stack is empty\n");
  else
    printf("Stack is not empty\n");

  stack_free(s);
}

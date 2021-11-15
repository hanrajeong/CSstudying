#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define init_capacity 3

typedef struct {
  int capacity;
  int* ar;
  int head;
} stack_t;

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
  s->capacity = init_capacity;
  s->ar = (int*)malloc(sizeof(int)*init_capacity);
  if(s->ar == NULL)
    return NULL;
  s->head = 0;
  return s;
}

int stack_push(stack_t* s, int item)
{
  if(s->capacity == s->head)
  {
    int* temp = (int*)realloc(s->ar, (s->capacity)*2*sizeof(int));
    if(temp==NULL)
      return -1;
    s->ar = temp;
    (s->capacity) *= 2;
  }
  s->ar[s->head]=item;
  (s->head)++;

  return item;
}

bool stack_is_empty(stack_t* s)
{
  return (s->head == 0);
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

void stack_free(stack_t* s)
{
  free(s->ar);
  free(s);
}

void print_stack(stack_t* s)
{
  for(int i = 0; i < s->head; i++)
    printf("%d ", s->ar[i]);
  printf("\n");
}

stack_t* copy_stack(stack_t* s)
{
  stack_t* new = stack_create();
  for(int i = 0; i < s->head; i++)
  {
    stack_push(new, s->ar[i]);
  }
  return new;
}

bool equal_stack(stack_t* s1, stack_t* s2)
{
  if(s1->head != s2->head)
    return false;
  for(int i = 0; i < s1->head; i++)
  {
    if(s1->ar[i] != s2->ar[i])
      return false;
  }
  return true;
}

void reverse_stack(stack_t* s)
{
  for(int i = 0; i < (s->head / 2); i++)
  {
    int temp = s->ar[i];
    s->ar[i] = s->ar[s->head - i - 1];
    s->ar[s->head - i - 1] = temp;
  }
}

stack_t* reverse_stack2(stack_t* s)
{
  stack_t* new = stack_create();
  for(int i = 0; i < (s->head); i++)
  {
    stack_push(new,s->ar[(s->head)-i-1]);
  }
  return new;
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

  print_stack(s);
  stack_t* s1 = copy_stack(s);
  print_stack(s1);
  printf(equal_stack(s, s1) ? "true" : "false");
  printf("\n");
  reverse_stack(s1);
  print_stack(s1);
  stack_t* s3 = reverse_stack2(s);
  print_stack(s3);

  stack_free(s);
}

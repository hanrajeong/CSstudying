#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  void* data;
  struct node* next;
} node_t;

typedef struct {
  node_t* head;
  node_t* tail;
} stack_t;

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
  s->head = NULL;
  s->tail = NULL;
  return s;
}

void stack_push(stack_t* s, void* item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode==NULL)
    return NULL;
  newNode->data = item;
  newNode->next = s->head;
  s->head = newNode;
}

void* stack_pop(stack_t* s)
{
  void* ret = s->head->data;
  s->head = s->head->next;
  return ret;
}

bool stack_is_empty(stack_t* s)
{
  return (s->head == NULL);
}

void stack_free(stack_t* s)
{
  while(!stack_is_empty(s))
    stack_pop(s);
  free(s);
}
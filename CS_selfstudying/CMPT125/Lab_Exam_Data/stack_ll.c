#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <assert.h>

typedef struct node {
  void* data;
  struct node* next;
} node_t;

typedef struct {
  int size;
  node_t* head;
  node_t* tail;
} LL_t;

typedef struct {
  LL_t* list;
} stack_t;

LL_t* LL_create()
{
  LL_t* l = (LL_t*)malloc(sizeof(LL_t));
  if(l==NULL)
    return NULL;
  l->size = 0;
  l->head = NULL;
  l->tail = NULL;

  return l;
}

void LL_add_to_head(LL_t* list, void* value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = list->head;
  if ((list->size) == 0)
    {
      // assert(list->head == NULL);
      // assert(list->tail == NULL);
      list->head = newNode;
      list->tail = newNode;
    }
    else
    {
      newNode->next = list->head;
      list->head = newNode;
    }
    (list->size)++;
}

void LL_add_to_tail(LL_t* list, void* value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode==NULL)
    return;
  newNode->data = value;
  newNode->next = NULL;
  if(list->size == 0)
  {
    // assert(list->head == NULL);
    // assert(list->tail == NULL);
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail->next = newNode;
    list->tail = newNode;
  }
  (list->size)++;
}

void* LL_remove_from_head(LL_t* list)
{
  void* ret = list->head->data;
  list->head = list->head->next;
  (list->size)--;
  if(list->size == 0)
  {
    // assert(list->head == NULL);
    list->tail = NULL;
  }
  return ret;
}

void* LL_remove_from_tail(LL_t* list)
{
  void* ret = list->tail->data;
  node_t* cur = list->head;
  while(cur->next != list->tail)
    cur = cur->next;
  list->tail = cur;
  list->tail->next = NULL;
  (list->size)--;
  
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LLnode_free(node_t* node)
{
  free(node);
}

void LL_free(LL_t* list)
{
  node_t* cur;
  while(list->head != NULL)
  {
    cur = list->head;
    list->head = cur->next;
    LLnode_free(cur);
  }
  free(list);
}

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  s->list = LL_create();
  return s;
}

void stack_push(stack_t* s, void* item)
{
  LL_add_to_head(s->list, item);
}

void* stack_pop(stack_t* s)
{
  return LL_remove_from_head(s->list);
}

int stack_is_empty(stack_t* s)
{
  return (LL_size(s->list)==0);
}

void stack_free(stack_t* s)
{
  LL_free(s->list);
  free(s);
}


int main() {
  stack_t* s = stack_create();
  if (s == NULL) {
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

  return 0;

}

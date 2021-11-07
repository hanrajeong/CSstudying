#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} node_t;

typedef struct{
  node_t* head;
  node_t* tail;
  int size;
} LL_t;

typedef struct{
  LL_t* list;
}stack_t;

LL_t* LL_create()
{
  LL_t* list = (LL_t*)malloc(sizeof(LL_t));
  if(list == NULL)
    return NULL;
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void LL_add_to_head(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->next = list->head;
  if((list->size) == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->head = newNode;
  }
  (list->size)++;
}

void LL_add_to_tail(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->next = NULL;
  if(list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail = newNode;
  }
  (list->size)++;
}

int LL_remove_from_head(LL_t* list)
{
  node_t* cur = list->head;
  int ret = cur->data;
  list->head = cur->next;
  (list->size)--;
  if(list->size == 0)
    list->tail = NULL;
  free(cur);
  return ret;
}

int LL_remove_from_tail(LL_t* list)
{
  node_t* cur = list->head;
  int ret = cur->data;
  while(cur->next != list->tail)
  {
    cur = cur->next;
  }
  list->tail = cur;
  (list->size)--;
  free(cur);
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  while(cur != NULL)
  {
    printf("%d ", cur->data);
    cur = cur->next;
  }
  free(cur);
  printf("\n");
}

void LL_free(LL_t* list)
{
  node_t* cur;
  while(list->head != NULL)
  {
    cur=list->head;
    list->head = cur->next;
    free(cur);
  }
  free(list);
}

stack_t* create_stack()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  s->list = LL_create();

  return s;
}

void stack_push(stack_t* s, int item)
{
  LL_add_to_head(s->list, item);
}

int stack_pop(stack_t* s)
{
  return LL_remove_from_head(s->list);
}

int stack_is_empty(stack_t* s)
{
  return (LL_size(s->list) == 0);
}

void stack_free(stack_t* s)
{
  free(s->list);
  free(s);
}

int main() {
  stack_t* s = create_stack();
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

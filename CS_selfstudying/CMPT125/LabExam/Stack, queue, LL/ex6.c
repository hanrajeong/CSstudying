#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
  int data;
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
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
  return l;
}

void LL_add_to_head(LL_t* list, int value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = list->head;
  if(list->size == 0)
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

void LL_add_to_tail(LL_t* list, int value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = NULL;
  if(list->size == 0)
  {
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

int LL_remove_from_head(LL_t* list)
{
  int ret = list->head->data;
  list->head = list->head->next;
  (list->size)--;
  if(list->size==0)
    list->tail = NULL;
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  for(;cur!=NULL;cur=cur->next)
  {
    printf("%d ", cur->data);
  }
}

void LL_free(LL_t* list)
{
  node_t* cur = list->head;
  while(list->head != NULL)
  {
    cur = cur->next;
    list->head = list->head->next;
    free(cur);
  }
  free(list);
}

stack_t* create_stack()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
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
  return (LL_size(s->list)==0);
}

void stack_free(stack_t* s)
{
  LL_free(s->list);
  free(s);
}

LL_t* copy_list(LL_t* s)
{
  LL_t* new = LL_create();
  node_t* cur = s->head;
  while(cur!=NULL)
  {
    LL_add_to_tail(new, cur->data);
    cur = cur->next;
  }  
  return new;
}

stack_t* copy_stack(stack_t* s)
{
  stack_t* new = create_stack();
  new->list = copy_list(s->list);
  return new;
}

bool eqaul_stacks(stack_t* s1, stack_t* s2)
{
  if(LL_size(s1->list)!=LL_size(s2->list))
    return false;
  node_t* cur1 = s1->list->head;
  node_t* cur2 = s2->list->head;
  while(cur1!=NULL && cur2!=NULL)
  {
    if(cur1->data != cur2->data)
      return false;
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  return true;
}

void rever_stack(stack_t* s)
{
  stack_t* temp = create_stack();
  while(s->list->head != NULL)
  {
    stack_push(temp, stack_pop(s));
  }
  s->list = temp->list;
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

  LL_print(s->list);
  printf("\n");

  stack_t* s1 = copy_stack(s);
  LL_print(s1->list);
  printf("\n");
  printf(eqaul_stacks(s, s1) ? "true" : "false");
  printf("\n");
  rever_stack(s);
  LL_print(s->list);
  printf("\n");

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

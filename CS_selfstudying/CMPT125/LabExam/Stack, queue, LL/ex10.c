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

typedef struct {
  stack_t* s1;
  stack_t* s2;
} queue_t;

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

queue_t* create_queue()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->s1 = create_stack();
  q->s2 = create_stack();
  return q;
}

void enqueue(queue_t* q, int item)
{
  if(stack_is_empty(q->s1))
    stack_push(q->s1, item);
  else
  {
    while(!stack_is_empty(q->s1))
    {
      stack_push(q->s2, stack_pop(q->s1));
    }
    stack_push(q->s1, item);
    while(!stack_is_empty(q->s2))
    {
      stack_push(q->s1, stack_pop(q->s2));
    }
  }
}

int dequeue(queue_t* q)
{
  return stack_pop(q->s1);
}

int queue_is_empty(queue_t* q)
{
  return stack_is_empty(q->s1);
}

int main() {
  queue_t* q = create_queue();
  if (q == NULL) {
    printf("could not create queue\n");
    return -1;
  }

  printf("enqueue(%d)\n", 1);
  enqueue(q, 1); // s = [1]
  printf("enqueue(%d)\n", 2);
  enqueue(q, 2); // s = [1,2]
  printf("enqueue(%d)\n", 3);
  enqueue(q, 3); // s = [1,2,3]
  printf("enqueue(%d)\n", 4);
  enqueue(q, 4); // s = [1,2,3,4]

  printf("dequeue = %d\n", dequeue(q));  // q = [2,3,4] print 1

  printf("enqueue(%d)\n", 5);
  enqueue(q, 5); // q = [2,3,4,5]

  printf("dequeue = %d\n", dequeue(q));  // s = [3,4,5] print 2

  printf("enqueue(%d)\n", 6);
  enqueue(q, 6); // s = [3,4,5,6]

  printf("dequeue = %d\n", dequeue(q)); // s = [4,5,6] print 3
  printf("dequeue = %d\n", dequeue(q)); // s = [5,6] print 4
  printf("dequeue = %d\n", dequeue(q)); // s = [6] print 5

  if (queue_is_empty(q))
    printf("Queue is empty\n");
  else
    printf("Queue is not empty\n");

  printf("dequeue = %d\n", dequeue(q)); // s = [] print 6

  if (queue_is_empty(q))
    printf("Queue is empty\n");
  else
    printf("Queue is not empty\n");
  
  return 0;
}

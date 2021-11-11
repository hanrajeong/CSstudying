#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node* next;
} node_t;

typedef struct {
  int size;
  node_t* head;
  node_t* tail;
} LL_t;

typedef struct{
  int len;
  LL_t* list;
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

void LL_add_to_head(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode -> data = item;
  newNode -> next = list->head;
  if(list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
    list->head = newNode;
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
    list->tail->next = newNode;
    list->tail = newNode;
  (list->size)++;
}

int LL_remove_from_head(LL_t* list)
{
  int ret = list->head->data;
  list->head = list->head->next;
  (list->size)--;
  if(list->size == 0)
    list->tail = NULL;
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_free(LL_t* list)
{
  node_t* cur;
  while(list->head != NULL)
  {
    cur = list->head;
    list->head = cur->next;
    free(cur);
  }
  free(list);
}

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  for(cur; cur!=NULL; cur=cur->next)
  {
    printf("%d ", cur->data);
  }
}

queue_t* create_queue(int n)
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->list = LL_create();
  q->len = n;
  return q;
}

void enqueue(queue_t* q, int data)
{
  if(q->list->size != q->len)
    LL_add_to_tail(q->list, data);
  else
  {
    LL_add_to_tail(q->list, data);
    LL_remove_from_head(q->list);
  }
}

int dequeue(queue_t* q)
{
  return LL_remove_from_head(q->list);
}


int main() {
  queue_t* q = create_queue(3);
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

  LL_print(q->list);
  return 0;
}

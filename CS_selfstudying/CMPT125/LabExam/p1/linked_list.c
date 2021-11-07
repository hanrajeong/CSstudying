#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
} node_t;

typedef struct{
  node_t* head;
  node_t* tail;
} LL_t;

LL_t* LL_create()
{
  LL_t* ll = (LL_t*)malloc(sizeof(LL_t));
  if(ll==NULL)
    return NULL;
  ll->head = NULL;
  ll->tail = NULL;

  return ll;
}

void LL_add_to_head(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->next = list->head;
  list->head = newNode;
}

void LL_add_to_tail(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->next = NULL;
  list->tail = newNode;
}

int LL_remove_from_head(LL_t* list)
{
  node_t* cur = list->head;
  int ret = cur->data;
  list->head = cur->next;
  free(cur);
  return ret;
}

int LL_remove_from_tail(LL_t* list)
{
  node_t* cur = list->head;
  while(cur->next != list->tail)
  {
    cur = cur->next;
  }
  int ret = cur->data;
  list->tail = cur;
  free(cur);
  return ret;
}

void LL_print(LL_t* list)
{
  node_t* cur;
  for(cur = list->head; cur!=NULL; cur=cur->next)
  {
    printf("%d ", cur->data);
  }
  printf("\n");
  free(cur);
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


int main()
{
  LL_t* list = LL_create();
  if(list == NULL)
  {
    return -1;
  }

  int N = 10;
  while(N){
    LL_add_to_head(list, N);
    N--;
  }

  LL_print(list);
  LL_free(list);

  return 0;
}
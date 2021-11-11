#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  struct node* next;
  struct node* prev;
} node_t;

typedef struct {
  int size;
  node_t* head;
  node_t* tail;
} DLL_t;

DLL_t* create_DLL()
{
  DLL_t* dll = (DLL_t*)malloc(sizeof(DLL_t));
  if(dll==NULL)
    return NULL;
  dll->head = NULL;
  dll->tail = NULL;
  dll->size = 0;
  return dll;
}

void add_to_front(DLL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->next = list->head;
  newNode->prev = NULL;
  if(list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->head->prev = newNode;
    list->head = newNode;
  }
  (list->size)++;
}

void add_to_end(DLL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->next = NULL;
  if(list->size==0)
  {
    newNode->prev = NULL;
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->tail = newNode;
  }
  (list->size)++;
}

int remove_from_front(DLL_t* list)
{
  int ret = list->head->data;
  list->head = list->head->next;
  list->head->prev = NULL;
  if(list->size == 0)
    list->tail = NULL;
  (list->size)--;
  return ret;
}

int remove_from_end(DLL_t* list)
{
  int ret = list->tail->data;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  if(list->size == 0)
    list->head = NULL;
  (list->size)--;
  return ret;
}

void DLL_print(DLL_t* list)
{
  node_t* cur;
  for(cur = list->head; cur!=NULL; cur=cur->next)
    printf("%d ", cur->data);
  printf("\n");
  free(cur);
}

int main()
{
  DLL_t* list = create_DLL();
  if(list == NULL)
  {
    return -1;
  }
  printf("1\n");

  int N = 5;
  while(N){
    add_to_front(list, N);
    N--;
  }
  printf("2\n");
  DLL_print(list);

  int M = 5;
  while(M){
    add_to_end(list, M);
    M--;
  }
  DLL_print(list);
  remove_from_front(list);
  
  DLL_print(list);
  remove_from_end(list);
  DLL_print(list);

  return 0;
}
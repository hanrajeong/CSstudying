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



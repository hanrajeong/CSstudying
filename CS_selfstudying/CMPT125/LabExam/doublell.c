#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node* next;
  struct node* prev;
} node_t;

typedef struct{
  node_t* head;
  node_t* tail;
  int size;
} LL_t;


LL_t* LL_create()
{
  LL_t* ll = (LL_t*)malloc(sizeof(LL_t));
  if(ll==NULL)
    return NULL;
  ll->head = NULL;
  ll->tail = NULL;
  ll->size = 0;
  return ll;
}

void LL_add_to_head(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = item;
  newNode->prev = NULL;
  newNode->next = list->head;
  if(list->head != NULL)
    list->head->prev = newNode;
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
  if(list->head==NULL)
  {
    newNode->prev = NULL;
    list->head = newNode;
  }
  if(list->tail != NULL)
  {
    newNode->prev = list->tail;
    list->tail->next = newNode;
  }
  list->tail = newNode;
  (list->size)++;
}

int LL_remove_from_head(LL_t* list)
{
  int ret = list->head->data;
  list->head=list->head->next;
  list->head->prev = NULL;
  (list->size)--;
  return ret;
}

int LL_remove_from_tail(LL_t* list)
{
  int ret = list->tail->data;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  (list->size)--;
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

int main () {
	LL_t* list = LL_create();
	if (list == NULL)
		return -1;

	int N = 10;
	while(N) {
		LL_add_to_tail(list, N);
		N--;
	}
	LL_print(list);
	LL_free(list);
	return 0;
}

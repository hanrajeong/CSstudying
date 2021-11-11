#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node* next;
} node_t;

typedef struct {
  int size;
  node_t* head;
  node_t* tail;
} LL_t;

LL_t* LLcreate()
{
  LL_t* l = (LL_t*)malloc(sizeof(LL_t));
  if(l==NULL)
    return NULL;
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
}

void LL_add_to_head(LL_t* list, int value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->value = value;
  newNode->next = list->head;
  list->head = newNode;
  if(list->size==0)
    list->tail = newNode;
  (list->size)++;
}

void LL_add_to_tail(LL_t* list, int value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->value = value;
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
  node_t* temp = list->head;
  int ret = temp->value;
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

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  for(;cur!=NULL;cur=cur->next)
  {
    printf("%d ", cur->value);
  }
}

void LL_free(LL_t* list)
{
  node_t* cur = list->head;
  while(list->head != NULL)
  {
    cur = list->head;
    list->head = list->head->next;
    free(cur);
  }
  free(list);
}

node_t* get_middle(LL_t* list)
{
  int mid = (list->size)/2;
  node_t* ret = list->head;
  for(int i = 0; i<mid; i++)
  {
    ret = ret->next;
  }
  return ret;
}

LL_t* copy_list(LL_t* orig)
{
  LL_t* new = LLcreate();
  if(new==NULL)
    return NULL;
  int len = orig->size;
  node_t* cur = orig->head;
  while(cur!=NULL)
  {
    LL_add_to_tail(new, cur->value);
    cur = cur->next;
  }
  return new;
}

bool equal_lists(LL_t* list1, LL_t* list2)
{
  if(list1->size != list2->size)
    return false;
  node_t* cur = list1->head;
  node_t* cur2 = list2->head;
  for(int i = 0; i<(list1->size); i++)
  {
    if(cur->value != cur2->value)
      return false;
    cur = cur->next;
    cur2 = cur2->next;
  }
  return true;
}

int main () {
	LL_t* list = LLcreate();
	if (list == NULL)
		return -1;

	int N = 10;
	while(N) {
		LL_add_to_head(list, N);
		N--;
	}
	LL_print(list);
  LL_t* list2 = copy_list(list);
  // list2->head->value = 5;
  printf("\n");
  LL_print(list2);
  node_t* cur = get_middle(list);
  printf("\n");
  printf(equal_lists(list, list2) ? "true" : "false");
  printf("\n");
  printf("The middle point is %d\n", cur->value);
	LL_free(list);
	return 0;
}

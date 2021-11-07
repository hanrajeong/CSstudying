#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node * next;
} node_t;

typedef struct {
  node_t* head;
  node_t* tail;
  int size;
} LL_t;

typedef struct {
  LL_t* list;
} stack_t;

LL_t* LLcreate()
{
  LL_t* list = malloc(sizeof(LL_t));
  if(list == NULL)
  {
    return NULL;
  }

  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

void LL_add_to_head(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
  {
    return;
  }
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
  {
    return;
  }
  newNode->data = item;
  newNode->next = NULL;
  if(list->size ==0)
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
  if((list->size)==0)
  {
    list->tail = NULL;
  }

  return ret;
}

int LL_remove_from_tail(LL_t* list)
{
  int ret = list->tail->data;
  node_t* current_node;
  while(current_node->next!=list->tail)
  {
    current_node = current_node->next;
  }
  list->tail = current_node;
  list->tail->next = NULL;

  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_print(LL_t* list)
{
  node_t* current = list->head;
  while(current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
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

stack_t* stack_creata()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  s->list = LLcreate();
  return s;
}

void stack_push(stack_t* s, int item)
{
  LL_add_to_head(s->list, item);
}

int stack_pop(stack_t*s, int item)
{
  return LL_remove_from_head(s->list);
}

int stack_is_empty(stack_t* s)
{
  return (LL_size(s->list) == 0);
}

void stack_free(stack_t* s)
{
  LL_free(s->list);
  free(s);
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
	LL_free(list);
	return 0;
}

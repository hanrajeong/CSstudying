#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node_t;

typedef struct {
  node_t* head;
  node_t* tail;
} LL_t;

LL_t* create_list()
{
  LL_t* list = malloc(sizeof(LL_t));
  if(list == NULL)
  {
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;

  return list;
}

void ll_add_head(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
  {
    return;
  }
  newNode->data = item;
  newNode->next = list->head;
  list->head = newNode;
}

void ll_add_tail(LL_t* list, int item)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
  {
    return;
  }
  newNode->data = item;
  newNode->next = NULL;
  list->tail = newNode;
}

int ll_remove_head(LL_t* list)
{
  node_t* current_node = list->head;
  int ret = current_node->data;

  list->head = current_node->next;

  free(current_node);

  return ret;
}

int ll_remove_tail(LL_t* list)
{
  node_t* current_node = list->head;
  while(current_node->next != list->tail)
  {
    current_node = current_node->next;
  }
  list->tail = current_node;
  int ret = current_node->data;

  free(current_node);

  return ret;
}

void LL_print(LL_t* list)
{
  node_t* current;
  for(current = list->head; current!=NULL; current=current->next)
  {
    printf("%d ", current->data);
  }
  printf("\n");
}

void LL_free(LL_t* list)
{
  node_t* current;
  while(list->head != NULL)
  {
    current = list->head;
    list->head = current->next;
    free(current);
  }
  free(list);
}

int main()
{
  LL_t* list = create_list();
  if(list == NULL)
  {
    return -1;
  }

  int N = 10;
  while(N){
    ll_add_head(list, N);
    N--;
  }

  LL_print(list);
  LL_free(list);

  return 0;
}
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
} queue_t;

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

queue_t* queue_create()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
  {
    return NULL;
  }
  q->list = LLcreate();
  if(q->list == NULL)
  {
    return NULL;
  }
  return q;
}

void enqueue(queue_t* q, int item)
{
  LL_add_to_tail(q->list, item);
}

int dequeue(queue_t* q)
{
  return LL_remove_from_head(q->list);
}

int queue_is_empty(queue_t* q)
{
  return (LL_size(q->list) == 0);
}

void queue_free(queue_t* q)
{
  LL_free(q->list);
  free(q);
}


int main() {
  queue_t* q = queue_create();
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
  
  queue_free(q); //error;;
  return 0;
}


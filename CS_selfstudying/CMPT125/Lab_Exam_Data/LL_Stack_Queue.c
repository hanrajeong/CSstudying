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

typedef struct {
  LL_t* list;
} stack_t;

typedef struct {
  LL_t* list;
} queue_t;

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

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  while(cur!=NULL)
  {
    printf("%d ", cur->data);
    cur=cur->next;
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
    LLnode_free(cur);
  }
  free(list);
}

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  s->list = LL_create();
  return s;
}

void stack_push(stack_t* s, void* item)
{
  LL_add_to_head(s->list, item);
}

void* stack_pop(stack_t* s)
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


queue_t* queue_create()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->list = LL_create();
  if(q->list == NULL)
    return NULL;
  return q;
}

void enqueue(queue_t* q, void* item)
{
  LL_add_to_tail(q->list, item);
}

void* dequeue(queue_t* q)
{
  return LL_remove_from_head(q->list);
}

bool queue_is_empty(queue_t* q)
{
  return (LL_size(q->list)==0);
}

void queue_free(queue_t* q)
{
  LL_free(q->list);
  free(q);
}

//--------------------------------------------------- PIAZZA implementation
node_t* get_middle(LL_t* list)
{
  int l = list->size;
  node_t* ret = list->head;
  for(int i = 0; i < l/2; i++)
  {
    ret = ret->next;
  }
  return ret;
}

LL_t* copy_list(LL_t* list)
{
  LL_t* l = LL_create();
  node_t* cur = list->head;
  while(cur!=NULL)
  {
    LL_add_to_tail(l, cur->data);
    cur = cur->next;
  }
  return l;
}

bool equal_list(LL_t* list1, LL_t* list2)
{
  if(list1->size != list2->size)
    return false;
  node_t* cur1= list1->head;
  node_t* cur2= list2->head;
  while(cur1!=NULL)
  {
    if(cur1->data != cur2->data)
    {
      return false;
    }
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  return true;
}

bool equal_queues(queue_t* q1, queue_t* q2)
{
  if(LL_size(q1->list) != LL_size(q2->list))
    return false;
  int len = LL_size(q1->list);
  node_t* cur = q1->list->head;
  node_t* cur2 = q2->list->head;
  for(int i = 0; i<len; i++)
  {
    if(cur->data != cur2->data)
      return false;
  }
  return true;
}

queue_t* copy_queue(queue_t* q)
{
  queue_t* ret = queue_create();
  ret->list =copy_list(q->list);
  return ret;
}

queue_t* reverse_queue(queue_t* q)
{
  // if(LL_size(q->list) <= 1)
  //   return q;
  queue_t* new = queue_create();
  node_t* cur1 = q->list->head;
  node_t* cur2 = q->list->tail;
  LL_add_to_tail(new->list, cur2->data);
  while(cur2!=q->list->head)
  {
    cur1 = q->list->head;
    while(cur1->next != cur2)
    {
      cur1 = cur1->next;
    }
    LL_add_to_tail(new->list, cur1->data);
    cur2 = cur1;
  }
  return new;
}

void reverse_queue2(queue_t* q)
{
  queue_t* new = queue_create();
  node_t* cur1 = q->list->head;
  node_t* cur2 = q->list->tail;
  LL_add_to_tail(new->list, cur2->data);
  while(cur2!=q->list->head)
  {
    cur1 = q->list->head;
    while(cur1->next != cur2)
    {
      cur1 = cur1->next;
    }
    LL_add_to_tail(new->list, cur1->data);
    cur2 = cur1;
  }
  cur2 = new->list->head;
  // while(cur2 != NULL)
  // {
  //   dequeue(q);
  //   enqueue(q, cur2->data);
  //   cur2 = cur2->next;
  // }
  q->list = new->list;
}

stack_t* copy_stack(stack_t* s)
{
  stack_t* new = stack_create();
  new->list = copy_list(s->list);
  return new;
}

bool equal_stacks(stack_t* s1, stack_t* s2)
{
  if(LL_size(s1->list) != LL_size(s2->list))
    return false;
  node_t* cur1 = s1->list->head;
  node_t* cur2 = s2->list->head;
  while(cur1!=NULL)
  {
    if(cur1->data != cur2->data)
      return false;
    cur1= cur1->next;
    cur2=cur2->next;
  }
  return true;
}

stack_t* reverse_stack(stack_t* s)
{
  stack_t* new = stack_create();
  node_t* cur1 = s->list->head;
  node_t* cur2 = s->list->tail;
  LL_add_to_tail(new->list, cur2->data);
  while(cur2!=s->list->head)
  {
    cur1 = s->list->head;
    while(cur1->next != cur2)
    {
      cur1 = cur1->next;
    }
    LL_add_to_tail(new->list, cur1->data);
    cur2 = cur1;
  }
  return new;
}

void reverse_stack2(stack_t* s)
{
  stack_t* temp = stack_create();
  while(s->list->head != NULL)
  {
    stack_push(temp, stack_pop(s));
  }
  s->list = temp->list;
}

int main () {
	LL_t* list = LL_create();
	if (list == NULL)
		return -1;

	int N = 10;
	while(N) {
		LL_add_to_head(list, (int*)N);
		N--;
	}
  node_t* n = get_middle(list);
  LL_t* list2 = copy_list(list);
	LL_print(list);
  LL_print(list2);
  printf("This two array is equal? ");
  printf(equal_list(list, list2) ? "true" : "false");
  printf("\n");
  printf("The middle node's value is %d\n", n->data);
	LL_free(list);

    queue_t* q = queue_create();
  if (q == NULL) {
    printf("could not create queue\n");
    return -1;
  }

  printf("enqueue(%d)\n", 1);
  enqueue(q, (int*)1); // s = [1]
  printf("enqueue(%d)\n", 2);
  enqueue(q, (int*)2); // s = [1,2]
  printf("enqueue(%d)\n", 3);
  enqueue(q, (int*)3); // s = [1,2,3]
  printf("enqueue(%d)\n", 4);
  enqueue(q, (int*)4); // s = [1,2,3,4]

  queue_t* q2 = copy_queue(q);
  printf("This two queues are same? ");
  printf(equal_queues(q, q2) ? "true" : "false");
  printf("\n");

  queue_t* q3 = reverse_queue(q);
  LL_print(q->list);
  LL_print(q3->list);
  reverse_queue2(q2);
  LL_print(q2->list);

  stack_t* s = stack_create();
  if (s == NULL) {
    printf("could not create stack\n");
    return -1;
  }

  printf("stack push(%d)\n", 1);
  stack_push(s, (int*)1); // s = [1]
  printf("stack push(%d)\n", 2);
  stack_push(s, (int*)2); // s = [1,2]
  printf("stack push(%d)\n", 3);
  stack_push(s, (int*)3); // s = [1,2,3]
  printf("stack push(%d)\n", 4);
  stack_push(s, (int*)4); // s = [1,2,3,4]

  LL_print(s->list);
  stack_t* s1 = copy_stack(s);
  LL_print(s1->list);
  printf(equal_stacks(s, s1) ? "true" : "false");
  printf("\n");
  stack_t* s2 = reverse_stack(s);
  LL_print(s2->list);
  reverse_stack2(s1);
  LL_print(s1->list);
  // rever_stack(s);
  printf("\n");

  
  stack_free(s);


	return 0;
}

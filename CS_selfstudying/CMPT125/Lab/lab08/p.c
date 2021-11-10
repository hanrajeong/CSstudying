#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node* next;
} node_t;

typedef struct {
  node_t* head;
  node_t* tail;
  int size;
} LL_t;

typedef struct {
  const char* name;
  int* data;
  int length;
  int capacity;
} my_array;

my_array* array_create(const char* nm, int init_size)
{
  my_array* ar = (my_array*)malloc(sizeof(my_array));
  if(ar==0)
    return NULL;
  ar->name = nm;
  ar->data = (int*)malloc(init_size*sizeof(int));
  ar->length = 0;
  ar->capacity = init_size;
  return ar;
}

int append(my_array* ar, int new_value)
{
  if(ar->length == ar->capacity)
  {
    ar->data = (int*)realloc(ar->data, (ar->capacity+1)*sizeof(int));
    (ar->capacity)++;
  }
  (ar->data)[ar->length] = new_value;
  (ar->length)++;
  return new_value;
}

void print_my_array(const my_array* ar) {
  for (int i=0; i<ar->length; i++)
    printf("%d ", ar->data[i]);
  printf("\n");
}

LL_t* LLcreate()
{
  LL_t* ret = malloc(sizeof(LL_t));
  ret->head = NULL;
  ret->tail = NULL;
  ret->size = 0;
}

void LL_add_to_head(LL_t* list, int value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = list->head;
  if(list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->head = newNode;
  }
  list->size++;
}

void LL_add_to_tail(LL_t* list, int value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = NULL;
  if(list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  list->tail->next = newNode;
  list->tail = newNode;
  (list->size)++;
}

int LL_remove_from_head(LL_t* list)
{
  node_t* temp = list->head;
  int ret = temp->data;
  list->head = list->head->next;
  (list->size)--;
  if((list->size)==0)
  {
    list->tail = NULL;
  }
  free(temp);
  return ret;
}

int LL_remove_from_tail(LL_t* list)
{
  node_t* temp = list->head;
  int ret = list->tail->data;
  while(temp->next != list->tail)
  {
    temp = temp->next;
  }
  temp -> next = NULL;
  list->tail = temp;
  (list->size)--;
  if((list->size)==0)
  {
    list->head = NULL;
  }
  free(temp);
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_print(LL_t* list)
{
  node_t* current = list->head;
  while(current!=NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void LL_print_reverse(LL_t* list)
{
  node_t* cur1 = list->tail;
  node_t* cur2 = list->head;
  printf("%d ", cur1->data);
  while(cur1 != cur2)
  {
    while(cur2->next != cur1)
    {
      cur2 = cur2->next;
    }
    printf("%d ", cur2->data);
    cur1 = cur2;
    cur2 = list->head;
  }
  printf("\n");
}

void LL_free(LL_t* list)
{
  node_t* cur;
  while(list->head != NULL)
  {
    cur = list->head;
    list->head = list->head->next;
    free(cur);
  }
  free(list);
}

my_array* to_array(LL_t* list, char* nm)
{
  my_array* ar = array_create(nm, list->size);
  node_t* current = list->head;
  while(current != NULL)
  {
    append(ar, current->data);
    current = current->next;
  }
  free(current);
  return ar;
}

LL_t* array_to_list(my_array* ar)
{
  LL_t* list = LLcreate();
  if(list==NULL)
    return NULL;
  for(int i = 0; i < (ar->length); i++)
  {
    LL_add_to_tail(list, (ar->data)[i]);
  }
  return list;
}

bool are_equal(LL_t* list1, LL_t* list2)
{
  node_t* cur1 = list1->head;
  node_t* cur2 = list2->head;
  if((list1->size)!=(list2->size))
  {
    return false;
  }
  while(cur1->next != NULL)
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

int main () {
  LL_t* list = LLcreate();
  if (list == NULL)
    return -1;

  int N = 10;
  while(N>0) {
    LL_add_to_head(list, N);
    N--;
  }
  for(N=0; N<10; N++)
    LL_add_to_tail(list, N);
  LL_print(list);

  printf("remove from head: %d\n", LL_remove_from_head(list));
  printf("remove from tail: %d\n",LL_remove_from_tail(list));
  LL_print(list);

  LL_print_reverse(list);
  my_array* newar1 = to_array(list, "newar1");
  print_my_array(newar1);
  LL_t* newll1 = array_to_list(newar1);
  LL_print(newll1);
  printf("%d\n", are_equal(list, newll1));

  LL_free(list);

  // test all other functions 

  return 0;
}


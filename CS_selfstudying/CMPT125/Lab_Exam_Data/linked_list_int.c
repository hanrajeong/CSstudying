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
    ar->data = (int*)realloc(ar->data, (ar->capacity*1)*sizeof(int));
    (ar->capacity)++;
  }
  (ar->data)[ar->length] = new_value;
  (ar->length)++;
  return new_value;
}

int get_length(const my_array* ar)
{
  return ar->length;
}

int get(const my_array* ar, int index)
{
  return ar->data[index];
}

int set(my_array* ar, int index, int value)
{
  return ar->data[index] = value;
}

void extend(my_array* ar1, my_array* ar2)
{
  int len = get_length(ar2);
  for(int i = 0; i < len; i++)
  {
    append(ar1, get(ar2, i));
  }
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

void LL_print_reverse(LL_t* list)
{
  node_t* cur1 = list->head;
  node_t* cur2 = list->tail;
  printf("%d ", cur2->data);
  while(cur1 != cur2)
  {
    while(cur1->next != cur2)
    {
      cur1 = cur1->next;
    }
    printf("%d ", cur1->data);
    cur2 = cur1;
    cur1 = list->head;
  }
}

my_array* to_array(LL_t* list)
{
  node_t* cur = list->head;
  int n = list->size;
  my_array* ar = array_create("ar", n);
  while(cur!=NULL)
  {
    append(ar, cur->data);
    cur = cur->next;
  }
  return ar;
}

LL_t* array_to_list(my_array* ar)
{
  LL_t* ret = LLcreate();
  int len = get_length(ar);
  for(int i = 0; i<len; i++)
  {
    LL_add_to_tail(ret, get(ar, i));
  }
  return ret;
}

bool are_equal(LL_t* ar1, LL_t* ar2)
{
  if(ar1->size != ar2->size)
    return false;
  node_t* cur1 = ar1->head;
  node_t* cur2 = ar2->head;
  while(cur1!=NULL)
  {
    if(cur1->data != cur2->data)
      return false;
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
  printf("\n");
  my_array* newar1 = to_array(list);
  print_my_array(newar1);
  LL_t* newll1 = array_to_list(newar1);
  LL_print(newll1);
  printf("%d\n", are_equal(list, newll1));

  LL_free(list);

  // test all other functions 

  return 0;
}


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "LL.h"



// Creates and returns a new, empty list
LL_t* LLcreate() {
    LL_t* ret = malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}


// Adds the element to the head of the list
void LL_add_to_head(LL_t* list, int value) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = list->head;

    if ((list->size) == 0) {
      assert(list->head == NULL);
      assert(list->tail == NULL);
      list->head = newNode;
      list->tail = newNode;
    }
    else {
      newNode->next = list->head;
      list->head = newNode;
    }

    (list->size)++;
}

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, int value)
{
 
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (list->size == 0) {
      assert(list->head == NULL);
      assert(list->tail == NULL);
      list->head = newNode;
      list->tail = newNode;
    }
    else {
      list->tail->next = newNode;
      list->tail = newNode;
    }

    (list->size)++;
}

// Removes the first element from a list
int LL_remove_from_head(LL_t* list)
{
  int ret = list->head->data;

 
  list->head = list->head->next;
  (list->size)--;
  if ((list->size)==0) {
    assert(list->head == NULL);
    list->tail = NULL;
  }
  return ret;
}


// Returns the size of the list
int LL_size(LL_t* list)
{
  return list->size;
}


// Prints the elements in the list from head to tail
void LL_print(LL_t* list) {
  node_t* current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}


// releases the memore used by node
void LLnode_free(node_t* node) {
  free(node);
}


// releases the memore used by list
void LL_free(LL_t* list) {
  node_t* cur;
  while (list->head != NULL) {
    cur = list->head;
    list->head = cur->next;
    LLnode_free(cur); 
  }
  free(list);
}

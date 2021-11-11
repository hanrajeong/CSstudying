#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "LL.h"



// Creates and returns a new, empty list
LL_t* LLcreate() {
    LL_t * ret = malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}


// Adds the element to the head of the list
void LL_add_to_head(LL_t* list, void* value)
{
    LLnode_t* newNode = (LLnode_t*) malloc(sizeof(LLnode_t));
    
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = list->head;

    if ((list->size) == 0)
    {
      assert(list->head == NULL);
      assert(list->tail == NULL);
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

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, void* value)
{
 
    LLnode_t* newNode = (LLnode_t*) malloc(sizeof(LLnode_t));
    
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (list->size == 0)
    {
      assert(list->head == NULL);
      assert(list->tail == NULL);
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

// Removes the first element from a list
void* LL_remove_from_head(LL_t* list)
{
  void* ret = list->head->data;

 
  list->head = list->head->next;
  (list->size)--;
  if ((list->size)==0)
  {
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


void LLnode_free(LLnode_t* node)
{
  free(node);
}


void LL_free(LL_t* list)
{
  LLnode_t* cur;
  while (list->head != NULL)
  {
    cur = list->head;
    list->head = cur->next;
    LLnode_free(cur); 
  }
  free(list);
}


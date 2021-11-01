#include <stdlib.h>
#include <stdio.h>

#include "LL.h"


// Creates and returns a new, empty list
LL_t* LLcreate() {
    LL_t* ret = malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    
    ret->head = NULL;
    return ret;
}


// Adds the element to the head of the list
void LL_add_to_head(LL_t* list, int value) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if (newNode == NULL)
    {
      printf("LL_add_to_head: malloc failed");
      return;
    }

    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}



// Remove the element from the head of the list
// Assumption: list is not empty
int LL_remove_from_head(LL_t* list) {
  node_t* current_head = list->head;
  int ret = current_head->data;

  list->head = current_head->next;

  free(current_head);
  return ret;
}


// Prints the elements in the list from head to tail
void LL_print(LL_t* list) {
  node_t* current;

  for (current = list->head; current != NULL ; current = current->next )
    printf("%d ", current->data);
  printf("\n");
}


void LLnode_free(node_t* node) {
  free(node);
}


void LL_free(LL_t* list) {
  node_t* cur;
  while (list->head != NULL) {
    cur = list->head;
    list->head = cur->next;
    LLnode_free(cur); 
  }
  free(list);
}


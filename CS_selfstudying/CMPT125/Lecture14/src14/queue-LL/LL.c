#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "LL.h"



// Creates and returns a new, empty list
LL_t* LLcreate() {
    LL_t* ret = malloc(sizeof(LL_t)); // We don't create new node, but just the empty object. Only the pointer to the first node.
    if (ret == NULL)
        return NULL;
    
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}

// 아래 코드 목적은 head가 첫번째 node를 point하고 있는데 제일 앞에 node를 삽입하는거니까, head가 newnode를 가르키고, newnode의
//next가 원래 첫번째 node를 가르키고 있어야함.
// Head가 Null을 가르키고 있었어서 다를 바 없이 적용가능. 그냥 newnode가 Null을 next로 point하고 있을뿐.
// Adds the element to the head of the list
void LL_add_to_head(LL_t* list, int value) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t)); // create new node
    
    if (newNode == NULL)
        return;

    newNode->data = value; // 순서가 data에 access해야하기 때문에 밑에 
    newNode->next = list->head; //list->head = newnode 선언 코드보다 선행해야함. or 더 이상 data에 access가 안되서 오류.

    if ((list->size) == 0) {
      assert(list->head == NULL);
      assert(list->tail == NULL);
      list->head = newNode; // head itself to be the newnode.
      list->tail = newNode;
    }
    else {
      newNode->next = list->head;
      list->head = newNode;
    }

    (list->size)++;
}

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, int value) {
 
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

// Let's assume the list is not empty
// Removes the first element from a list
int LL_remove_from_head(LL_t* list) {
  int ret = list->head->data;

 
  list->head = list->head->next;
  (list->size)--;
  if ((list->size)==0) {
    assert(list->head == NULL);
    list->tail = NULL;
  }
  return ret; // return the deleted data
}


// Returns the size of the list
int LL_size(LL_t* list) {
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

// 교수님이 가지고 계신 코드랑 조금 달랐음.
// for(current = list->head; current->data; )이런식이었음.


// releases the memore used by node
void LLnode_free(node_t* node)
{
  free(node);
}

// we need to free the memory one by one.
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

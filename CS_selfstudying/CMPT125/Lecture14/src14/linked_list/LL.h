#ifndef LL_H
#define LL_H


#include "LL-node.h"


typedef struct {
	node_t* head;
} LL_t;


// Creates and returns a new, empty list
LL_t* LLcreate();


// Adds a new element to the head  of a list
void LL_add_to_head(LL_t* list, int value);

// Remove the element from the head of the list
int LL_remove_from_head(LL_t* list);


// Prints the list elements in order from head to tail
void LL_print(LL_t* list);


// releases the memore used by list
void LL_free(LL_t* list);

#endif
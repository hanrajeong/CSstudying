#ifndef LL_H
#define LL_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node  node_t;

// linked list with pointers to head and tail
typedef struct {
  node_t* head;
  node_t* tail;
  int size;
} LL_t;


// Creates and returns a new, empty list
LL_t * LLcreate();

// creates an array with the elements
// of the list in the same order
void to_array(LL_t* list);

// gets an array of length n
// returns a list with the elements
LL_t* array_to_list(int* ar, int n);

// Adds a new element to the head of a list
void LL_add_to_head(LL_t* list, int value);

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, int value);

// Removes the first element from a list
int LL_remove_from_head(LL_t* list);

// Removes the last element from a list
int LL_remove_from_tail(LL_t* list);

// Returns the size of the list
int LL_size(const LL_t* list);

// prints the list elements in order from head to tail
void LL_print(const LL_t * list);

// print the list elements in order from tail to head
void LL_print_reverse(const LL_t * list);

// checks if the two lists are equal
bool are_equal(const LL_t * list1, const LL_t * list2);


// releases the memore used by list
void LL_free(LL_t* list);


#endif

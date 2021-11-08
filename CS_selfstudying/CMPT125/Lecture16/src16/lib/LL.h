#ifndef LL_H
#define LL_H

struct node {
	void* data; // pointer to any type
	struct node* next;
};

typedef struct node LLnode_t;


typedef struct {
	LLnode_t* head;
	LLnode_t* tail;
  int size;
} LL_t;


// Creates and returns a new, empty list
LL_t* LLcreate();


// Adds a new element to the head of a list
void LL_add_to_head(LL_t* list, void* value);

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, void* value);

// Removes the first element from a list
void* LL_remove_from_head(LL_t* list);

// Prints the list
void LL_print(LL_t* list);

// Returns the size of the list
int LL_size(LL_t* list);

// releases the memore used by list
void LL_free(LL_t* list);


#endif

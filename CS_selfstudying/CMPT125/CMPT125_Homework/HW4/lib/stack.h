#ifndef STACK_H
#define STACK_H

struct node {
	char data;
	struct node * next;
};

typedef struct node node_t;


typedef struct {
  node_t* head;
  node_t* tail;
} stack_t; 

// creates a new stack
stack_t* stack_create();

// pushes a given item to the stack
void stack_push(stack_t* s, char item);

// remove an item from the top of the stack
char stack_pop(stack_t* s);

//  checks if stack is empty
bool stack_is_empty(stack_t* s);

// frees the stack
void stack_free(stack_t* s);


#endif

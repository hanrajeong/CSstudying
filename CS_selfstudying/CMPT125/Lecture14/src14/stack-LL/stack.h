#ifndef STACK_H
#define STACK_H

#include "LL.h"


typedef struct {
  LL_t* list;
} stack_t; 

// creates a new stack
stack_t* stack_create();

// pushes a given item to the stack
// Pre condition: stack is not empty
void stack_push(stack_t* s, int item);

// pops the top element from the stack
// Pre condition: stack is not empty
int stack_pop(stack_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s);

// releases the memory
void stack_free(stack_t* s);


#endif

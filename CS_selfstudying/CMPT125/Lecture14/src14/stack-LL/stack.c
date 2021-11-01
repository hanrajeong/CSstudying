#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// creates a new stack
// Q: why are we returning a pointer?
stack_t* stack_create() {
  stack_t* s = (stack_t*) malloc(sizeof(stack_t));
  s->list = LLcreate();
  return s;
}

// pushes a given item to the stack
// Pre condition: stack is not empty
// Q: why do we need a pointer to s?
void stack_push(stack_t* s, int item) {
  LL_add_to_head(s->list, item);
}

// pops the top element from the stack
// Pre condition: stack is not empty
// Q: why do we need a pointer to s?
int stack_pop(stack_t* s) {
  return LL_remove_from_head(s->list);
}

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s) {
    return (LL_size(s->list) == 0);
}


// releases the memory
void stack_free(stack_t* s) {
  LL_free(s->list);
  free(s);
}





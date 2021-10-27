#ifndef STACK1_H
#define STACK1_H

// this is maximal possible capacity of our stack
#define MAX_SIZE 100


// stack of bounded capacity 
typedef struct {
    int size;
    int* ar;
    int head;
} stack_t; 

// creates a new stack
// Q: why are we returning a pointer?
stack_t* stack_create();

// pushes a given item to the stack
// Q: why do we need a pointer to s?
void stack_push(stack_t* s, int item);

// pops the top element from the stack
// Pre condition: stack is not empty
// Q: why do we need a pointer to s?
int stack_pop(stack_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s);

// releases the memory used by stack
void stack_free(stack_t* s);

#endif
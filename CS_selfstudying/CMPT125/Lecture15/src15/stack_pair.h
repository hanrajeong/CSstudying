#ifndef STACK2_H
#define STACK2_H


#define INIT_CAPACITY 3

typedef struct {
  int first;
  int second;
} pair;

// stack of bounded capacity 
typedef struct {
    int capacity;
    pair* ar;
    int head;
} stack_t; 

// creates a new stack
stack_t* stack_create();

// pushes a given item to the stack
// Returns item if the operation is successful
pair stack_push(stack_t* s, pair item);

// pops the top element from the stack
// Pre condition: stack is not empty
pair stack_pop(stack_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s);

// returns 1 if the stack is empty, and returns 0 otherwise
void stack_free(stack_t* s);

#endif
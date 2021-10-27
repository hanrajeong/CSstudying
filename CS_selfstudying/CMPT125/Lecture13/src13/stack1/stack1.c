#include <stdio.h>
#include <stdlib.h>

#include "stack1.h"


// creates a new stack
// Q: why are we returning a pointer?
stack_t* stack_create()
{
    stack_t* s = (stack_t*) malloc(sizeof(stack_t));
    if (s == NULL)
      return NULL;

    s->ar = (int*) malloc(MAX_SIZE*sizeof(int));
    if (s->ar == NULL)
      return NULL;

    s->size = MAX_SIZE;
    s->head = 0;
    return s;
}

// pushes a given item to the stack
// Q: why do we need a pointer to s?
// Q: what happens when more than MAX_SIZE elements are added?
void stack_push(stack_t* s, int item)
{
    (s->ar)[s->head] = item;
    (s->head)++;
}

// pops the top element from the stack
// Pre condition: stack is not empty
// Q: why do we need a pointer to s?
int stack_pop(stack_t* s)
{
    if (stack_is_empty(s))
    {
      printf("STACK IS EMPTY!");
      return -1;
    }

    //        |
    //        v
    // [1,2,3,4,0,0,0,0,0]
    (s->head)--;
    //      |
    //      v
    // [1,2,3,4,0,0,0,0,0]

    return (s->ar)[s->head];
}

// returns 1 if the stack is empty, and returns 0 otherwise
int stack_is_empty(stack_t* s)
{
    return (s->head==0);
}

// releases the memory used by stack
void stack_free(stack_t* s)
{
    free(s->ar);
    free(s);
}

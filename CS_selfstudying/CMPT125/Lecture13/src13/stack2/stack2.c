#include <stdio.h>
#include <stdlib.h>

#include "stack2.h"


// creates a new stack
// Q: why are we returning a pointer?
stack_t* stack_create()
{
    stack_t* s = (stack_t*) malloc(sizeof(stack_t));
    if (s == NULL)
      return NULL;

    s->ar = (int*) malloc(INIT_CAPACITY*sizeof(int));
    if (s->ar == NULL)
      return NULL;

    s->capacity = INIT_CAPACITY;
    s->head = 0;
    return s;
}

// pushes a given item to the stack
// Returns item if the operation is successful
// Q: why do we need a pointer to s?
int stack_push(stack_t* s, int item)
{

    if (s->head == s->capacity)
    {
        int* tmp_ar = (int*) realloc(s->ar, (s->capacity)*2*sizeof(int));

        // handling relloc failure
        if (tmp_ar == NULL)
          return -1;

        s->ar = tmp_ar;

        s->capacity = (s->capacity)*2;

        printf("increase size --> %d\n", s->capacity);
    }

    (s->ar)[s->head] = item;
    (s->head)++;

    return item;
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
    (s->head)--;
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

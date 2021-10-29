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
    (s->ar)[s->head] = item; // 여기서 pointer인 head는 가장 마지막에 넣은 last element의 다음 위치를 가르키고 있음.
    (s->head)++; // 따라서 push를 하는 경우 pointer의 위치를 옮겨야함.
}
//예를 들어
//[1, 2, 3]
//         ^
//push(4)
//[1, 2, 3, 4]
//            ^ 
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
    (s->head)--; // move head down by one, and return that value, head의 위치가 가장 마지막 element의 다음 위치를 가르키고
    //      | 있었으니까, 한칸 앞으로 당겨서 head --로, 포인팅하는 element를 반환하고, 그 자리가 비었다고 생각하는 것.
    //      v 실제로 값을 없애거나 하는 것은 아니고 pointer가지고 노는 것.
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

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


// creates a new queue
queue_t* queue_create() {
  queue_t* q = (queue_t*) malloc(sizeof(queue_t));
  if (q==NULL)
    return NULL;

  q->list = LLcreate();
  if (q->list==NULL)
    return NULL;
  
  return q;
}

// enqueue a given item to the queue
void enqueue(queue_t* q, int item) {
  LL_add_to_tail(q->list, item);
}

// dequeue from the queue
// Pre condition: queue is not empty
int dequeue(queue_t* q) {
    return LL_remove_from_head(q->list);
}

// returns 1 if the queue is empty, and returns 0 otherwise
int queue_is_empty(queue_t* q) {
    return (LL_size(q->list) == 0);
}

// free queue
void queue_free(queue_t* q) {
    LL_free(q->list);
    free(q);
}

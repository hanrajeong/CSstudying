#include <stdlib.h>
#include <stdio.h>

#include "queue.h"



int main() {
  queue_t* q = queue_create();
  if (q == NULL) {
    printf("could not create queue\n");
    return -1;
  }

  printf("enqueue(%d)\n", 1);
  enqueue(q, 1); // s = [1]
  printf("enqueue(%d)\n", 2);
  enqueue(q, 2); // s = [1,2]
  printf("enqueue(%d)\n", 3);
  enqueue(q, 3); // s = [1,2,3]
  printf("enqueue(%d)\n", 4);
  enqueue(q, 4); // s = [1,2,3,4]

  printf("dequeue = %d\n", dequeue(q));  // q = [2,3,4] print 1

  printf("enqueue(%d)\n", 5);
  enqueue(q, 5); // q = [2,3,4,5]

  printf("dequeue = %d\n", dequeue(q));  // s = [3,4,5] print 2

  printf("enqueue(%d)\n", 6);
  enqueue(q, 6); // s = [3,4,5,6]

  printf("dequeue = %d\n", dequeue(q)); // s = [4,5,6] print 3
  printf("dequeue = %d\n", dequeue(q)); // s = [5,6] print 4
  printf("dequeue = %d\n", dequeue(q)); // s = [6] print 5

  if (queue_is_empty(q))
    printf("Queue is empty\n");
  else
    printf("Queue is not empty\n");

  printf("dequeue = %d\n", dequeue(q)); // s = [] print 6

  if (queue_is_empty(q))
    printf("Queue is empty\n");
  else
    printf("Queue is not empty\n");
  
  queue_free(q); //error;;
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define maxsize 10

typedef struct{
  int* ar;
  int head;
  int tail;
} queue_t;

int queue_is_empty(queue_t* q);

queue_t* create_queue()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->ar = (int*)malloc(sizeof(int)*maxsize);
  if(q->ar==NULL)
    return NULL;
  q->head = 0;
  q->tail = 0;
}

int enqueue(queue_t* q, int item)
{
  if(((q->tail)+1)%maxsize == q->head)
  {
    return -1; // queue is full
  }
  (q->ar)[q->tail] = item;
  (q->tail) = ((q->tail)+1)%maxsize;
  
  return item;
}

int dequeue(queue_t* q)
{
  if(queue_is_empty(q))
  {
    return -1;
  }
  int ret = (q->ar)[q->head];
  (q->head) = (q->head + 1)%maxsize;

  return ret;
}

int queue_is_empty(queue_t* q)
{
  return (q->head == q->tail);
}

void queue_free(queue_t* q)
{
  free(q->ar);
  free(q);
}


int main()
{
  queue_t* s = create_queue();
  if(s==NULL)
  {
    printf("could not creat stack\n");
  }

  enqueue(s, 1);
  enqueue(s, 2);
  enqueue(s, 3);
  enqueue(s, 4);
  printf("%d ", dequeue(s));
  printf("%d ", dequeue(s));
  printf("%d ", dequeue(s));
  printf("%d ", dequeue(s));
  printf("\n");
  printf("%d ", queue_is_empty(s));

  queue_free(s);
}
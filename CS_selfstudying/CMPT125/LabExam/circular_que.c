#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct{
  int head;
  int tail;
  int* ar;
} queue_t;

int queue_is_empty(queue_t* q);


queue_t* create_queue()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q == NULL)
  {
    return NULL;
  }
  q->ar = (int*)malloc(MAXSIZE*sizeof(int));
  if(q->ar == NULL)
  {
    return NULL;
  }
  q->head = 0;
  q->tail = 0;

  return q;
}

int enqueue(queue_t* q, int item)
{
  if(((q->tail)+1)%MAXSIZE == q->head)
  {
    printf("queue is full");
    return -1;
  }
  (q->ar)[q->tail] = item;
  q->tail = ++(q->tail) % MAXSIZE;
  // printf("head is %d tail is %d \n", q->head, q->tail);

  return item;
}

int dequeue(queue_t* q)
{
  if(queue_is_empty(q))
  {
    printf("queue is empty");
    return -1;
  }

  int re = (q->ar)[q->head];
  q->head = ++(q->head)%MAXSIZE;

  // printf("head is %d tail is %d \n", q->head, q->tail);

  return re;
}

int queue_is_empty(queue_t* q)
{
  if(q->head == q->tail)
    return 1;
  else
    return 0;
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define init_capacity 3

typedef struct {
  int tail;
  int head;
  int* ar;
  int capacity;
} queue_t;

queue_t* create_queue()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->ar = (int*)malloc((init_capacity)*sizeof(int));
  if(q->ar == NULL)
    return NULL;
  q->head = 0;
  q->tail = 0;
  q->capacity = init_capacity;
  return q;
}

bool queue_is_empty(queue_t* q)
{
  return (q->head == q->tail);
}

int enqueue(queue_t* q, int item)
{
  if(q->tail == q->capacity)
  {
    int* temp = (int*)realloc(q->ar, (q->capacity)*2*sizeof(int));
    if(temp == NULL)
      return -1;
    q->ar = temp;
    q->capacity *= 2;
  }
  q->ar[q->tail] = item;
  (q->tail) += 1;

  return item;
}

int dequeue(queue_t* q)
{
  if(queue_is_empty(q))
    return -1;
  int ret = q->ar[q->head];
  for(int i = 0; i < (q->tail); i++)
  {
    (q->ar)[i] = (q->ar)[i+1];
  }
  (q->tail)--;
  return ret;
}

void queue_free(queue_t* q)
{
  free(q->ar);
  free(q);
}

void queue_print(queue_t* q)
{
  for(int i = 0; i < q->tail; i++)
    printf("%d ", q->ar[i]);
  printf("\n");
}

queue_t* copy_queue(queue_t* q)
{
  queue_t* new = create_queue();
  for(int i = 0; i < q->tail; i++)
  {
    enqueue(new, q->ar[i]);
  }
  return new;
}

bool equal_queues(queue_t* q1, queue_t* q2)
{
  if(q1->tail != q2->tail)
    return false;
  for(int i = 0; i < q1->tail; i++)
  {
    if(q1->ar[i] != q2->ar[i])
      return false;
  }
  return true;
}

queue_t* reverse_queue(queue_t* q)
{
  queue_t* new = create_queue();
  for(int i = (q->tail)-1; i>=0; i--)
  {
    enqueue(new, q->ar[i]);
  }
  return new;
}

bool reverse_queue2(queue_t* q)
{
  for(int i = 0; i < (q->tail)/2; i++)
  {
    int temp = q->ar[i];
    q->ar[i] = q->ar[q->tail-i-1];
    q->ar[q->tail-i-1] = temp;
  }
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
  queue_print(s);
  queue_t* q = copy_queue(s);
  queue_print(q);
  printf(equal_queues(s, q) ? "true" : "false");
  printf("\n");
  queue_t* q1 = reverse_queue(q);
  queue_print(q1);
  reverse_queue2(q);
  queue_print(q);
  queue_free(s);
}
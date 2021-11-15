#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define initsize 3

typedef struct{
  int first;
  int second;
} pair;

typedef struct{
  int capacity;
  pair* ar;
  int head;
} stack_t;

int stack_is_empty(stack_t* s);

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
  s->ar = (pair*)malloc(initsize*sizeof(pair));
  if(s->ar == NULL)
    return NULL;
  s->capacity = initsize;
  s->head = 0;

  return s;
}

pair stack_push(stack_t* s, pair item)
{
  if(s->head == s->capacity)
  {
    pair* temp = (pair*)realloc(s->ar, (s->capacity)*2*sizeof(pair));
    if(temp == NULL)
      return (pair){-1, -1};
    
    s->ar = temp;
    s->capacity = (s->capacity)*2;

  }
  (s->ar)[s->head] = item;
  (s->head)++;

  return item;
}

pair stack_pop(stack_t* s)
{
  if(stack_is_empty(s))
  {
    return (pair){-1, -1};
  }
  (s->head)--;
  return (s->ar)[s->head];
}

int stack_is_empty(stack_t* s)
{
  return (s->head==0);
}

void stack_free(stack_t* s)
{
  free(s->ar);
  free(s);
}

void print_array(int* ar, int n)
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

void swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int rearrange(int *ar, int n, int pivot_index)
{
  if(n<=1)
    return n;

  int pivot_value = ar[pivot_index];

  swap(&ar[0], &ar[pivot_index]);

  int* temp = (int*)malloc(n*sizeof(int));
  int left = 0;
  int right = n-1;
  for(int i = 1; i<n; i++)
  {
    if(ar[i]<=pivot_value)
      temp[left++] = ar[i];
    else
      temp[right--] = ar[i];
  }
  // printf("%d %d\n", left, right);
  temp[left] = pivot_value;
  memcpy(ar, temp, n*sizeof(int));
  free(temp);

  // printf("%d %d\n", ar[left], ar[right]);

  return left;
}

void quick_sort(int* ar, int n)
{
  stack_t* s = stack_create();
  stack_push(s, (pair){0, n-1});

  int p1, p2;
  while(!stack_is_empty(s))
  {
    pair next = stack_pop(s);
    p2 = rearrange(ar+next.first, next.second-next.first+1, 0);
    p1 = p2 + next.first;

    if(p1+1<next.second)
      stack_push(s,(pair){p1+1,next.second}); // pivot +1 의 index와 오른쪽 끝의 인덱스를 push
    if(p1-1>next.first)
      stack_push(s,(pair){next.first, p1-1}); // 처음과 pivot -1 의 위치를 push
  }
  free(s);
}

int main() {

  int a[] = {5,3,1,7,2,4,8};
  int n = 7;
//  rearrange(a,7,0);
  quick_sort(a,n);

  print_array(a,n);
  return 0;
}
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

stack_t* stack_create() {
  stack_t* s = (stack_t*) malloc(sizeof(stack_t));
  s->head = NULL;
  s->tail = NULL;
  return s;
}

void stack_push(stack_t* s, char item) {
  node_t* new_head = (node_t*) malloc(sizeof(node_t));
  new_head->data = item;
  new_head->next = s->head;
  s->head = new_head;
}

char stack_pop(stack_t* s) {
  node_t* prev_head = s->head;
  char ret = prev_head->data;
  s->head = prev_head->next;
  free(prev_head);
  return ret;
}

bool stack_is_empty(stack_t* s) {
    return (s->head == NULL);
}


void stack_free(stack_t* s) {
  while (!stack_is_empty(s))
    stack_pop(s);
  free(s);
}


int stack_size(stack_t* s) {
  stack_t* s1 = (stack_t*)malloc(sizeof(stack_t));
  int count = 0;
  int a = 0;
  while (!stack_is_empty(s))
  {
    a = stack_pop(s);
    stack_push(s1, a);
    count++;
  }
  while (!stack_is_empty(s1))
  {
    a = stack_pop(s1);
    stack_push(s, a);
  }
  free(s1);
  return count;
}

bool stack_equal(stack_t* s1, stack_t* s2) {
  bool flag = true;
  if(stack_size(s1)!=stack_size(s2))
  {
    flag = false;
    return flag;
  }
  int a, b;
  stack_t* s3 = (stack_t*)malloc(sizeof(stack_t));
  stack_t* s4 = (stack_t*)malloc(sizeof(stack_t));
  while (!stack_is_empty(s1))
  {
    a = stack_pop(s1);
    b = stack_pop(s2);
    if(a!=b)
    {
      flag = false;
    }
    stack_push(s3, a);
    stack_push(s4, b);
  }
  while (!stack_is_empty(s3))
  {
    a = stack_pop(s3);
    stack_push(s1, a);
  }
  while (!stack_is_empty(s4))
  {
    a = stack_pop(s4);
    stack_push(s2, a);
  }
  stack_free(s3);
  stack_free(s4);
  return flag;
}


int main()  
{
  stack_t* s1 = stack_create();
  stack_t* s2 = stack_create();
  int i=0;

  for (i=0;i<20;i++) stack_push(s1, 'a'+i);
  for (i=0;i<20;i++) stack_push(s2, 'a'+i);
  bool is_eq1 = stack_equal(s1, s2);

  int size = stack_size(s1);

  // for (i=0;i<5;i++) stack_push(s1, '0'+i);
  // for (i=0;i<5;i++) stack_push(s2, '0'+i);

  // bool is_eq2 = stack_equal(s1, s2);

  stack_free(s2);
  stack_free(s1);

  // if (is_eq1 && is_eq2 && size==20)  {
  //   printf("Q1b ok\n");
  //   return true;
  // }
  // else  {
  //   printf("Q1b ERROR\n");
  //   return false;
  // }

}

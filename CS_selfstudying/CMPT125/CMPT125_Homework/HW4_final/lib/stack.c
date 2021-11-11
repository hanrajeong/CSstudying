#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

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





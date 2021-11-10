#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

int stack_size(stack_t* s) {
  stack_t* q1_s = stack_create();
  int count = 0;
  int a = 0;
  while (!stack_is_empty(s))
  {
    a = stack_pop(s);
    stack_push(q1_s, a);
    count++;
  }
  while (!stack_is_empty(q1_s))
  {
    a = stack_pop(q1_s);
    stack_push(s, a);
  }
  stack_free(q1_s);
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
  stack_t* s3 = stack_create();
  stack_t* s4 = stack_create();
  while (!stack_is_empty(s1))
  {
    a = stack_pop(s1);
    b = stack_pop(s2);
    if(a!=b)
    {
      flag = false;
      break;
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


char* stack_to_string(stack_t* s) {
  int size = stack_size(s);
  char* res = (char*)malloc(size*sizeof(char));
  stack_t* s1 = stack_create();
  char a;
  for(int i = 0; i < size; i++)
  {
    a = stack_pop(s);
    res[size-i-1] = a;
    stack_push(s1, a);
  }
  return res;
}

bool is_leaf(BTnode_t* root)
{
  return (root->left == NULL && root->right == NULL);
}

int size(BTnode_t* root)
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
    return 1;
  else
    return size(root->left) + size(root->right) + 1;
}

int length(BTnode_t* root)
{
  int result;
  char* temp;
  if(root==PLUS || root==MULT || root==MINUS || root==DIV)
    result = 1 + length(root->left) + length(root->right);
  else
  {
    if(root->value > 99 && root->value < 1000)
      result = 3 + length(root->left) + length(root->right);
    else if(root->value <100 && root->value > 9)
      result = 2 + length(root->left) + length(root->right);
    else if(root->value < 10 && root->value >= 0)
      result = 1 + length(root->left) + length(root->right);
    else if(root->value > (-10) && root->value < 0)
      result = 2 + length(root->left) + length(root->right);
    else if(root->value > (-1000) && root->value < (-99))
      result = 3 + length(root->left) + length(root->right);
  }
}

char* get_arithmetic_expression(BTnode_t* expression) {
  if(expression = NULL)
    return;
  get_arithmetic_expression(expression->left);
  printf("%d", expression->data);
  get_arithmetic_expression(expression->right);
  return NULL;
}


BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
  // implement me
  return NULL;
}


void map(BTnode_t* root, int (*f)(int)) {
  // implement me
  return;
}


BTnode_t* copy_tree(BTnode_t* root) {
  // implement me
  return NULL;
}



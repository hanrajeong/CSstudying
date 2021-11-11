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

int leaf_size(BTnode_t* root)
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
    return 1;
  else
    return leaf_size(root->left) + leaf_size(root->right);
}

int length(BTnode_t* root)
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
  {
    if(root->value > 99 && root->value < 1000)
      return 3;
    else if(root->value <100 && root->value > 9)
      return 2;
    else if(root->value < 10 && root->value >= 0)
      return 1;
    else if(root->value > (-10) && root->value < 0)
      return 2;
    else if(root->value > (-1000) && root->value < (-99))
      return 3;
  }
  else
    return length(root->left) + length(root->right) + 1;
  return 0;
}

void print_qtn(BTnode_t* expression, char* str)
{
  if(expression==NULL)
    return;
  print_qtn(expression->left, str);
  if(expression->value == PLUS)
  {
    printf("here");
    strcat(str, "+");
  }
  else if(expression->value == MINUS)
  {
    printf("here1");
    strcat(str, "-");
  }
  else if(expression->value == MULT)
  {
    printf("here3");
    strcat(str, "*");
  }
  else if(expression->value == DIV)
  {
    printf("here4");
    strcat(str, "/");
  }
  else
  {
    printf("here5");
    sprintf(str, "%d", expression->value);
  }
  print_qtn(expression->right, str);
}

int memory_length(BTnode_t* expression)
{
  int len = 0;
  if(size(expression)==1)
    len = length(expression);
  else
  {
    len = (size(expression) - leaf_size(expression) - 1)*2 + length(expression) + size(expression) -1 + (size(expression) - leaf_size(expression) - 1)*2;
  }
  return len;
}

BTnode_t* find_left(BTnode_t* root)
{
  if(root->left != NULL)
    return find_left(root->left);
  return root;
}

BTnode_t* find_right(BTnode_t* root)
{
  if(root->right != NULL)
    return find_right(root->right);
  return root;
}

void print_inorder(BTnode_t* root, char* str, int* index, BTnode_t* left, BTnode_t* right)
{
  if(root==NULL)
    return;
  if(root->left!=NULL)
  {
    if(root->left!=left)
    {
      *index += sprintf(&str[*index], "(");
      str[*index] = ' ';
      *index += 1;
    }
    print_inorder(root->left, str, index, left, right);
  }
  if(root->value == PLUS)
  {
    str[*index] = ' ';
    *index += 1;
    str[*index] = '+';
    *index += 1;
    str[*index] = ' ';
    *index += 1;
  }
  else if(root->value == MINUS)
  {
    str[*index] = ' ';
    *index += 1;
    str[*index] = '-';
    *index += 1;
    str[*index] = ' ';
    *index += 1;
  }
  else if(root->value == MULT)
  {
    str[*index] = ' ';
    *index += 1;
    str[*index] = '*';
    *index += 1;
    str[*index] = ' ';
    *index += 1;
  }
  else if(root->value == DIV)
  {
    str[*index] = ' ';
    *index += 1;
    str[*index] = '/';
    *index += 1;
    str[*index] = ' ';
    *index += 1;
  }
  else
  {
    *index += sprintf(&str[*index], "%d", root->value);
  }
  if(root->right != NULL)
  {
    print_inorder(root->right, str, index, left, right);
    if(root->right != right)
    {
      str[*index] = ' ';
      *index += 1;
      *index += sprintf(&str[*index], ")");
    }
  }
}

char* get_arithmetic_expression(BTnode_t* expression) {
  char* str = (char*)malloc((memory_length(expression)+1)*sizeof(char));
  if(expression == NULL)
    return NULL;
  BTnode_t* left = find_left(expression);
  BTnode_t* right = find_right(expression);
  int index = 0;
  print_inorder(expression, str, &index, left, right);
  str[index]='\0';
  return str;
}

BTnode_t* find(BTnode_t* root, bool (*pred)(int)) 
{
  if(pred(root->value)==1)
    return root;
  find(root->left, pred);
  find(root->right, pred);
  return NULL;
}


void map(BTnode_t* root, int (*f)(int)) {
  if(root==NULL)
    return;
  root->value = f(root->value);
  map(root->left, f);
  map(root->right, f);
}


BTnode_t* copy_tree(BTnode_t* root) {
  if(root==NULL)
    return NULL;
  BTnode_t* new = (BTnode_t*)malloc(sizeof(BTnode_t));
  new->left = copy_tree(root->left);
  new->right = copy_tree(root->right);
  new->value = root->value;
  return new;
}



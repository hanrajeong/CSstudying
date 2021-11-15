#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

int stack_size(stack_t* s) {
  stack_t* q1_s = stack_create();
  int count = 0; // this will be used to count the size of the stack
  while (!stack_is_empty(s)) // pop the elements of the stack untile it is empty
  {
    stack_push(q1_s, stack_pop(s)); // store this elements to the temp stack, 
    // the question asked to not change the stack, so will be used to put elements back to orginial stack
    count++; // count the number of the popped elements
  }
  while (!stack_is_empty(q1_s))
  {
    stack_push(s, stack_pop(q1_s)); //put every elements back to the original stack
  }
  stack_free(q1_s);
  return count;
}
// Helper function to check whether the given stack is not changed after the each function operated.
// void stack_print(stack_t* s)
// {
//   stack_t* s1 = stack_create();
//   while(!stack_is_empty(s))
//   {
//     stack_push(s1, stack_pop(s));
//   }
//   while (!stack_is_empty(s1))
//   {
//     char c = stack_pop(s1);
//     printf("%c", c);
//     stack_push(s, c); //put every elements back to the original stack
//   }
//   stack_free(s1);
//   printf("\n");
// }

bool stack_equal(stack_t* s1, stack_t* s2) {
  bool flag = true;
  if(stack_size(s1)!=stack_size(s2)) // just for case these two stacks have different size, check it to be more efficient
  {
    flag = false;
    return flag;
  }
  int a, b; // Although the question said the type of the elements in the stack will be char, but the given test case included the case
  // where the elements' type is int, since every char can be expressed as the int, I decided to use the type integer for the temporality stored varaible.
  stack_t* s3 = stack_create();
  stack_t* s4 = stack_create();
  while (!stack_is_empty(s1))
  {
    a = stack_pop(s1);
    b = stack_pop(s2);
    stack_push(s3, a);
    stack_push(s4, b);
    if(a!=b) // check whether the popped elements are same, and if they are not same, stop iteration and return the value
    {
      flag = false;
      break;
    }
  }
  while (!stack_is_empty(s3)) // put every elements back to the stack.
  {
    a = stack_pop(s3);
    stack_push(s1, a);
  }
  while (!stack_is_empty(s4))
  {
    a = stack_pop(s4);
    stack_push(s2, a);
  }
  stack_free(s3); // free the temporarily used stacks
  stack_free(s4);
  return flag;
}

char* stack_to_string(stack_t* s) {
  int size = stack_size(s);
  char* res = (char*)malloc((size+1)*sizeof(char)); // allocate memory for the strings
  stack_t* s1 = stack_create();
  for(int i = 0; i < size; i++)
  {
    res[size-i-1] = stack_pop(s); // since the stack's pop happens at the end, in order to store the string in order, we need to start to store it from the end.
    stack_push(s1, res[size-i-1]);
  }
  while(!stack_is_empty(s1))
  {
    stack_push(s, stack_pop(s1));
  }
  res[size] = '\0'; // put the stop mark at the end. this is why I allocate the memory as size+1;
  return res;
}

bool is_leaf(BTnode_t* root) // helper function to check whether it is a leaf
{
  return (root->left == NULL && root->right == NULL);
}

int size(BTnode_t* root) // helper function to check the size of the tree
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
    return 1;
  else
    return size(root->left) + size(root->right) + 1;
}

int leaf_size(BTnode_t* root) // helper function check the number of leaf
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
    return 1;
  else
    return leaf_size(root->left) + leaf_size(root->right);
}

int length(BTnode_t* root) // helper function to check the length of the value of each node.
// This is to decide the memory requirements for the string.
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

int memory_length(BTnode_t* expression) // This is helper function to calculate total memory requirements to generate equation as the string
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

BTnode_t* find_left(BTnode_t* root) // This is helper function to find left-most node
{
  if(root->left != NULL)
    return find_left(root->left);
  return root;
}

BTnode_t* find_right(BTnode_t* root) // This is helper function to find right-most node
{
  if(root->right != NULL)
    return find_right(root->right);
  return root;
}

void print_inorder(BTnode_t* root, char* str, int* index, BTnode_t* left, BTnode_t* right)
{ // This is helper function to print
  if(root==NULL)
    return;
  if(root->left!=NULL)
  {
    if(root->left!=left) // check whether it is equal to the left most node, because if it is, we shouldn't print (.
    {
      *index += sprintf(&str[*index], "("); // since sprintf function returns the length of the memory it stores
      str[*index] = ' '; // we can use it as to know the stored index
      *index += 1;
    }
    print_inorder(root->left, str, index, left, right); // do the recursion
  }
  if(root->value == PLUS) // Since we don't know what to store when we meet the plus, minus, mult, div
  { // This is for telling the system what to store as the string.
    str[*index] = ' ';
    *index += 1; // Plus the index by 1 as stored space
    str[*index] = '+';
    *index += 1; // Plus the index by 1 as arithmetic expression
    str[*index] = ' ';
    *index += 1; // Plus the index by 1 as stored space
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
    *index += sprintf(&str[*index], "%d", root->value); // plus the index number by returned length given by sprintf, as it returns total length of the string that it stored
  }
  if(root->right != NULL)
  {
    print_inorder(root->right, str, index, left, right);
    if(root->right != right) // check whether it is equal to the right most node, because if it is, it shouldn't print ) at the end.
    {
      str[*index] = ' ';
      *index += 1;
      *index += sprintf(&str[*index], ")");
    }
  }
}

char* get_arithmetic_expression(BTnode_t* expression) {
  char* str = (char*)malloc((memory_length(expression)+1)*sizeof(char)); // get the memory length by calculating total number of length we need
  if(expression == NULL) // Just for checking whether the given node is NULL or not
    return NULL;
  BTnode_t* left = find_left(expression);
  BTnode_t* right = find_right(expression);
  int index = 0;
  print_inorder(expression, str, &index, left, right);
  str[index]='\0'; // put the ending mark at the end. this is why I put the memory length as memory_length(expression)+1
  return str;
}

BTnode_t* find(BTnode_t* root, bool (*pred)(int)) 
{
  // if there are many nodes satisfy the boolean function, should return the first node in pre-order
  // so before doint the recursion, check whether the root satisfies the boolean function
  // and then return the result of it.
  if(pred(root->value)==1) // if there is such node that satisfies the given bool function,
    return root; // return the pointer to the node.
  find(root->left, pred); // do the recursion,
  find(root->right, pred);
  return NULL;
}


void map(BTnode_t* root, int (*f)(int)) {
  if(root==NULL) // stop condition
    return;
  root->value = f(root->value); // change each node's value with the given function operation
  map(root->left, f); // do the recursion.
  map(root->right, f);
}


BTnode_t* copy_tree(BTnode_t* root) {
  if(root==NULL) // stop condition
    return NULL;
  BTnode_t* new = (BTnode_t*)malloc(sizeof(BTnode_t)); // make the new tree;
  new->left = copy_tree(root->left);
  new->right = copy_tree(root->right);
  new->value = root->value;
  return new;
}



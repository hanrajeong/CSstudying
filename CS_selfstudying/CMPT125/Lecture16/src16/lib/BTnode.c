  #include <stdio.h>
#include <stdlib.h>

#include "BTnode.h"

BTnode_t* create_node(int val) {
    BTnode_t* newNode = (BTnode_t*) malloc(sizeof(BTnode_t));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

void set_left_child(BTnode_t* parent, BTnode_t* left_child) {
  if (parent)
    parent->left = left_child;
  if (left_child)
    left_child->parent = parent;
}

void set_right_child(BTnode_t* parent, BTnode_t* right_child) {
  if (parent)
    parent->right = right_child;
  if (right_child)
    right_child->parent = parent;
}

void print_pre_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  printf("%d ", root->value);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

void print_in_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  print_in_order(root->left);
  printf("%d ", root->value);
  print_in_order(root->right);
}

void print_post_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->value);
}


void print_ancestors(BTnode_t* node, LL_t* list_of_ancestors) {
  // print the list
  printf("list of ancestors for %d:", node->value);

  LLnode_t* ancestor_LLnode = list_of_ancestors->head;
  while (ancestor_LLnode!=NULL)  
  {
    // casting from void* to BTnode_t*
    printf(" %d", ((BTnode_t*) ancestor_LLnode->data)->value);
    ancestor_LLnode = ancestor_LLnode->next; // move forward in the list
  }
  printf("\n");
}

LL_t* list_of_ancestors(BTnode_t* node) {

  LL_t* list = LLcreate();
  
  BTnode_t* current = node;
  while (current!=NULL)
  {
    LL_add_to_head(list, current); // add current vertex to the list
    current = current->parent; // go up in the tree
  }

  print_ancestors(node, list);

  return list;
}



int BTdistance(BTnode_t* n1, BTnode_t* n2) {
  // the list of ancestors has root at the beginning and n1 in the end
  LL_t* l1 = list_of_ancestors(n1);
  // the list of ancestors has root at the beginning and n2 in the end
  LL_t* l2 = list_of_ancestors(n2);

  LLnode_t* ancestor1 = l1->head;
  LLnode_t* ancestor2 = l2->head;
  int common = 0;

  printf("common ancestors: ");
  // compare the pointers to the ancestors nodes
  while ( (ancestor1->data)==(ancestor2->data) )
  {
    // casting element of the list  from void* to BTnode_t* 
    printf("%d ", ((BTnode_t*)(ancestor1->data))->value); 
    common++;
    ancestor1 = ancestor1->next; // move forward in the linked list1
    ancestor2 = ancestor2->next; // move forward in the linked list2
  }
  printf("\n");
  
  int distance = LL_size(l1) + LL_size(l2) - 2*common;
  LL_free(l1);
  LL_free(l2);
  return distance;
}



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int is_leaf(BTnode_t* root) {
  return (root->left == NULL && root->right == NULL);
}

int size(BTnode_t* root) {
  if (root==NULL)
    return 0;
 else // add +1 for the root
    return size(root->left) + size(root->right) + 1;
}

int max(int x, int y) {
  return x>y ? x : y;
}

// assume root is not NULL
int height(BTnode_t* root) {
  if (root == NULL)
    return -1;
//  else if (is_leaf(root))
//    return 0;
  else
    return max(height(root->left), height(root->right))+1;
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


int count_leaves(BTnode_t* root) {
  // implement me
  return -1;
}

int* in_order_to_array(BTnode_t* root) {
  // implement me
  return NULL;
}

bool are_equal(BTnode_t* root1, BTnode_t* root2) {
  // implement me
  return false;
}


BTnode_t* reconstruct_tree(int* inorder, int* preorder, int n) {
  // implement me
  return NULL;
}

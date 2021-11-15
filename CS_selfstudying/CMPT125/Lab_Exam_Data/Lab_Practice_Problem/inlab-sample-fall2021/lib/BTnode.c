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


#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

// creates a Binary Search Tree
BST_t* BST_create()
{
  BST_t* tree = (BST_t*) malloc(sizeof(BST_t));
  tree->root = NULL;
  return tree;
}

BTnode_t* BST_find(BST_t* tree, int item) {
  
  BTnode_t* current = tree->root;
  while (current!=NULL) {
    if (current->value == item)
      return current;
    if (current->value > item)
      current = current->left;
    else
      current = current->right;
  }
  // item not found
  return NULL;
}

// inserts item into the Binary Search Tree
void BST_insert(BST_t* tree, int item)
{
  if (tree->root == NULL)   {
    printf("set %d as the root\n", item);
    tree->root = create_node(item);
    return;
  }
//   add 7 to the tree below
//
//       n5 ->
//      /  \
//    n2  <-n8
//   / \    / \
// n1  n3 n6-> n9
//           \
//add 7 here: 7

  BTnode_t* current = tree->root;
  BTnode_t* prev = NULL;
  while (current!=NULL)  {
    prev = current;
    // decide to go left or right in the next step 
    if (current->value > item)
      current = current->left;
    else
      current = current->right;
  }
  // now prev holds the lowest node in our path
  if (prev->value > item) {
    printf("add %d to left of %d\n", item, prev->value);
    set_left_child(prev, create_node(item));
  }
  else {
    printf("add %d to right of %d\n", item, prev->value);
    set_right_child(prev, create_node(item));
  }
}

// removes item from the Binary Search Tree
void BST_remove(BST_t* tree, int item)
{
  // implement me
}

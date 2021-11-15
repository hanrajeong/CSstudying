#ifndef BTNODE_H
#define BTNODE_H

#include <stdbool.h>


struct BTnode {
  int value;
  struct BTnode* left;
  struct BTnode* right;
  struct BTnode* parent;
};

typedef struct BTnode BTnode_t;

BTnode_t* create_node(int value);

void set_left_child(BTnode_t* parent, BTnode_t* left_child);

void set_right_child(BTnode_t* parent, BTnode_t* right_child);

int size(BTnode_t* root);

int height(BTnode_t* root);

void print_pre_order(BTnode_t* root);

void print_in_order(BTnode_t* root);

void print_post_order(BTnode_t* root);


// count the number of leaves in the tree
int count_leaves(BTnode_t* root);

// returns an array containing inOrder traversal 
// on the tree with the given root
int* in_order_to_array(BTnode_t* root);

// check if two trees are equal
// meaning they have the same structure
// with exactly the same values
bool are_equal(BTnode_t* root1, BTnode_t* root2);


// The function gets  two arrays of length n
// one contains the inorder of some tree
// the other containsthe preorder of the same tree
// The function reconstructs the tree
// ** prove that such tree is uniquely defined **
BTnode_t* reconstruct_tree(int* inorder, int* preorder, int n);


#endif
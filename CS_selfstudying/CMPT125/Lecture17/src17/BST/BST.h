#ifndef BST_H
#define BST_H

#include "BTnode.h"


typedef struct BST {
  BTnode_t* root;
} BST_t;

BST_t* BST_create();

BTnode_t* BST_find(BST_t* tree, int item);

void BST_insert(BST_t* tree, int item);

void BST_remove(BST_t* tree, int item);


#endif
#ifndef BTNODE_H
#define BTNODE_H


#include "LL.h"

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

void print_pre_order(BTnode_t* root);

void print_in_order(BTnode_t* root);

void print_post_order(BTnode_t* root);

LL_t* list_of_ancestors(BTnode_t* node);

int BTdistance(BTnode_t* n1, BTnode_t* n2);


#endif
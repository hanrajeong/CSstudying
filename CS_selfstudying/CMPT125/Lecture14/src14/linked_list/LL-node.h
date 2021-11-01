#ifndef LLNODE_H
#define LLNODE_H


struct node {
	int data;
	struct node* next;
};

typedef struct node node_t;

#endif
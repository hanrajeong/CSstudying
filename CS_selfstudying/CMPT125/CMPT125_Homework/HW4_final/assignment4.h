#include <stdbool.h>

#include "lib/stack.h"
#include "lib/BTnode.h"

#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H

/* Question 1 */

// returns the size of the stack
int stack_size(stack_t* s);

// checks if the two stacks are equal
bool stack_equal(stack_t* s1, stack_t* s2);

// converts stack to a string
// For example, suppose we push 'A', then 'B', and then 'C'.
// The function needs to return the string "ABC".
char* stack_to_string(stack_t* s);



/* Question 2 */

enum {PLUS = '+', MINUS = '-', MULT = '*', DIV = '/'};

// converts a arithmetic expression from tree to string
char* get_arithmetic_expression(BTnode_t* expression);


/* Question 3 */

// finds the first node in pre-order satisfying pred
// if such node not found, returns NULL
BTnode_t* find(BTnode_t* root, bool (*pred)(int));


// appies f to each node of the tree under root
void map(BTnode_t* root, int (*f)(int));


// creates a new copy of the tree
BTnode_t* copy_tree(BTnode_t* root);



#endif

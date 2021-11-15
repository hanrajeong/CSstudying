#include <stdbool.h>

#include "lib/BTnode.h"


#ifndef SAMPLE_H
#define SAMPLE_H

// a1 is an array of length len1
// a2 is array of length len2
// returns true if every value of a1 is contained in a2
bool contains(const int* a1, int len, const int* a2, int len2);

 
// returns the length of the last word in str
int last_len(const char* str);


// gets a root of a binary tree, and returns the sum of all numbers in it
// if the tree is empty, returns 0
int BT_sum(const BTnode_t* root);


#endif

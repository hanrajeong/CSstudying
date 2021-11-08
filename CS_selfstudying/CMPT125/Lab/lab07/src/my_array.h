#include <stdbool.h>
#include <stdlib.h>

/*
    Implementation of array of ints
    Allows operations such as: createing an empty array, get/set value
    my_array allows increasing length using the add function
*/

// protects in case the file is inlucede several times
#ifndef MY_ARRAY_H
#define MY_ARRAY_H


// This file contains only declarations of functions
// the implementaion is in my_array.c

typedef struct {
    const char* name;
    int* data;
    int length; // current length of the array - allowed incides are 0...length-1
    int capacity; // actual amount of memory allocated
} my_array;

// creates an empty array of given initial capacity
my_array* create_my_array(const char* name, int init_size);

// returns the length of the array
int get_length(const my_array* ar);

// returns the i'th element in the array
int get(const my_array* ar, int index);

// sets the i'th element in the array to be the specified value
// returns the set value
// Assumption: index < length of the array
int set(my_array* ar, int index, int value);

// increases the length of the array by 1
// and sets new_value in the last entry
int append(my_array* ar, int new_value);

// concatenates ar2 to the end of ar1
void extend(my_array* ar1, const my_array* ar2);

// prints all elements of the array
void print_my_array(const my_array* ar);

#endif
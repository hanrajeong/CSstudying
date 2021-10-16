#include <stdbool.h>


#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

typedef struct {
  char* title;
  char* artist;
  int year;
} song;

// The function gets the name of a file, and a song.
// If the song is not in the file, the function adds it to the file and returns 1.
// Otherwise, the function does not modify the file and returns 0.
int add_song(const char* file_name, const song s);


// The function gets the name of a file and a title of a song.
// It searches the file for the song with the given title.
// If song is found, it returns a pointer to the song with all the details.
// If not found, the function returns NULL.
song* find_song(const char* file_name, const char* title);


// The function computes the fib3 function defined as follows:
// fib3(0) = 0
// fib3(1) = 1
// fib3(2) = 2
// fib3(n) = fib(n-1)+fib(n-2)+fib(n-3) for all n>=3
// That is, the sequence is 0,1,2,3,6,11,20,37,68,125...
unsigned long fib3(unsigned int n);


// Recursive implementation of linear search.
// If number is in the array, the function returns the first index.
// containing the number.
// If number is not in the array, the function returns -1.
int linear_search_rec_first(int* ar, int length, int number);

// Recursive implementation of linear search.
// If number is in the array, the function returns the last index
// containing the number.
// If number is not in the array, the function returns -1.
int linear_search_rec_last(int* ar, int length, int number);



// The function gets a string str, and a char delim.
// It returns the number of tokens in the string separated by delim.
int count_tokens(const char* str, char delim);

// The function get_tokens gets a string str, and a char delim
// It returns an array of tokens (strings) in the correct order.
// The length of the array is the number of tokens, computed in count_tokens.
char** get_tokens(const char* str, char delim);

#endif

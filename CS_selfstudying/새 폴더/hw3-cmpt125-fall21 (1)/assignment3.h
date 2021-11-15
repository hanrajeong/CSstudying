#include <stdbool.h>

#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

typedef struct {
  int x;
  int y;
} point;

/* Question 1 */

// used for QuickSort:
// the function rearranges the elements, and
// returns the index of the pivot after the rearrangement
// The function follows runs in O(n) time using the algorithm we saw in class
int rearrange(int* A, int n, int pivot_index);

// QuickSort algorithm
// If n<=2, just sort the two elements (greater number first)
// For n>=3 use your rearrange function as a subroutine with pivot chosen to be the median of A[0],A[n/2],A[n-1]
void quick_sort(int* A, int n);



/* Question 2 */

// sorts an array of sort_points using qsort
void sort_points(point* A, int length);


/* Question 3 */

// The function gets an array A of length n of ints, and a boolean predicate p.
// It returns the smallest index i such that p(A[i])==true.
// If no such element is not found, the function returns -1.
int find(int* A, int n, bool (*pred)(int));


// The function gets an array A of length n of ints, and a function f
// It applies f to each element of A
void map(int* A, int n, int (*f)(int));


// The function gets an array A of length n of ints, and a function f.
// The function f gets 2 ints and works as follows:
// * Start with accumulator = A[0]
// * For i=1...length-1 compute accumulator=f(accumulator, A[i])
// *Return accumulator
// For example, if f computes the sum of the two inputs
// then reduce() will compute the sum of the entire array
int reduce(int* A, int n, int (*f)(int,int));



#endif

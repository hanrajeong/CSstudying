#include <stdio.h>
#include <stdlib.h>


void print_array(int* ar, int n) {
  for (int i=0; i < n; i++)
    printf("%d ", ar[i]);
  printf("\n");
}

// gets the array populated in the first len positions
// and the max value used so far
int print_k_sequences_helper(int n, int k, int* ar, int len, int max_so_far) {
  if (len == k) {
    print_array(ar, k);
    return 1;
  }

  // if n is already used then we cannot extend the sequence
  if (max_so_far == n)
    return 0;

  //len < k, and max_in_ar < n
  int total = 0; // returned value

  // set the next value in the array and apply recursion
  // for example: for n=10, k=5 if ar = [1,2,5]
  // then we will try to add 6,7,8,9,10 as the next value and call recursion
  for (int j=max_so_far+1; j<=n; j++)
  {
    ar[len] = j;
    total += print_k_sequences_helper(n, k, ar, len+1, j);
  }
  
  return total;
  
}


int print_k_sequences(int n,int k) {
  int* ar = (int*) malloc(k * sizeof(int));

  // invoke helper function
  // requires an array of length k to store the intermediate values
  int ret = print_k_sequences_helper(n, k, ar, 0, 0);
  free(ar);
  return ret;
}



// an iterative solution
// the algorithm that given a sequence finds the next sequence in "alphabetic" order
// For example, let n = 20, k = 7
// the first sequence will be [1,2,3,4,5,6,7]
// the last sequence will be [14,15,16,17,18,19,20]
//
// Suppose the previous seuqence is [1,3,4,5,18,19,20]
// then the next sequence will be [1,3,4,6,7,8,9]
int print_k_sequences_iter(int n,int k) {
  int i,j; // temp variables

  int total = 0;
  int* ar = (int*) malloc(k * sizeof(int));

  for (i = 0; i < k; i++) // initialize the first seqeunce
    ar[i] = i+1;

  while (ar[0] <= n-k) { // ar[0] = n-k+1 <=> this is the last sequence
    print_array(ar, k);
    total++;

    //find the rightmost element that can be increased
    // Suppose the previous seuqence is [1,3,4,5,18,19,20]
    // we find 5    
    int i = k-1;
    while (ar[i] == n-(k-1-i))
      i--;

    // change 5 to 6 and update everying to the right
    // then the next sequence will be [1,3,4,6,7,8,9]
    ar[i]++;
    for (j=i+1; j < k; j++)
      ar[j] = ar[j-1]+1;
  }

  print_array(ar, k); // print the  sequence
  total++;          // update the counter

  return total;
}


int main() {
  int num = print_k_sequences(5,3);
  printf("the total number of sequences is %d", num);
  return 0;
}

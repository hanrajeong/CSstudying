#include <stdio.h>
#include <string.h>
 

void bad_recursion_static(int* str, int n) {
  static int i = 0; // due to the static variable, if we call this function twice, there will be errors, unexpected values returned
  // do not use STATIC VARIABLE!
  if(i<n) {
    printf("%d ", str[i]);
    i++;
    bad_recursion_static(str,n);
  }
}

void print_rec(int* str, int n) { // it is adding the elements to the stack every time, so n-1 more elements
// actually using more memory?
  if(n>=1) 
  {
    printf("%d ", str[0]);
    print_rec(str+1,n-1);
  }
}

void print_rec_rev(int* str, int n)
{
  if(n>=1)
  {
    print_rec_rev(str+1, n-1);
    printf("%d ", str[0]);
  }
}

int main(void) {
  int a[] = {1,2,3,4};
  printf("printing a:");
  print_rec(a,4);

  printf("\n");

  printf("printing reversively a: ");
  print_rec_rev(a, 4);

//  bad_recursion_static(a,4);
  int b[] = {1,2,3,4,5,6,7,8,9};
  printf("\nprinting b:");
  print_rec(b,9);
//  bad_recursion_static(b,9);
  return 0;
}
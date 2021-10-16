#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
          fib(8)
        /       \
     fib(7)     fib(6)
    /   \       /   \
 fib(6)fib(5) fib(5)fib(4)
 ....
*/
// get a number n >= 0
// returns fib(n)

//재귀함수의 경우 memory 사용량 및 time이 많이 걸리기 때문에 비추천!!!
//교수님은 재귀함수 좋아하시지 않음.

long fib(int n)
{
/*  if (n == 0) return 0;
    if (n == 1)   return 1;
*/
  if (n <= 1)
    return n;
  else
    return fib(n-1) + fib(n-2);
} 


// get a number n >= 0
// returns fib(n)
long fib_array(int n)
{
  // the array stores fib(i) in array_fib[i]
  long* array_fib = (long*) malloc( (n+1) * sizeof(long));
  if (array_fib == NULL)
    return -1; 
  
  array_fib[0] = 0;
  array_fib[1] = 1;
 
  // populate the array one element at a time from 2 to n
  for (int i = 2; i<=n; i++)
  {
    array_fib[i] = array_fib[i-1] + array_fib[i-2];
  }
  return array_fib[n];
} 

// compute fib(n) using formula
long fib_formula(int n)
{
  double base = 1.61803398875; // (sqrt(5)+1)/2 =
  return round(pow(base, n)/sqrt(5));
} 

int main() { 
  int n = 70;
  printf("fib-array(%d)    = %ld\n", n, fib_array(n) );
//  printf("fib-slow(%d)    = %ld\n", n, fib(n) );
  printf("fib-formula(%d) = %ld\n", n, fib_formula(n) );

  printf("\n-------\n\n");
  printf("sizeof long is %lu bytes\n", sizeof(long));
  long huge = 1;
  huge = (huge << 63) - 1;
  printf("huge number = %ld\n", huge);
  printf("trying to add 1 to it...\n");
  huge = huge+1;
  printf("huge number = %ld\n", huge);
  return 0;
}

// https://www.sfu.ca/computing/about/support/csil/how-to-rdp-into-a-csil-workstation.html
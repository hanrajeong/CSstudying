#include <stdio.h>

// // assumption n>=0
// int bar(int a, int n) {
//  if (n == 0)
//    return 0;
//  int half = n/2; // round down if n is odd
//  int tmp = bar(a,half);
//  if (n%2 == 0)
//  {
//    printf("%d + %d\n", tmp, tmp);
//    return tmp+tmp;
//  }
    
//  else
//  {
//    printf("%d + %d + %d\n", tmp, tmp, a);
//    return tmp+tmp+a;
//  }
// }

int bar(int a, int n)
{
  return n*a;
}

int main(void)
{
  printf("%d", bar(6, 11));
}
#include <stdio.h>


int main() {
  
  unsigned int x = 65536; // 2^16
  printf("%u\n", x);

  x = x*65536;  // 2^32
  printf("%u\n", x); // will print 0

  x--;	// -1? 
  printf("%u\n", x);

  return 0;
}

#include <stdio.h>
#include <limits.h>



void printBits(unsigned char x)
{
  int i;
  int byte[8];

  for (i=0; i <= 7; i++) {
    byte[7-i] = x%2; // sets 0 if x is odd, sets 1 if x is even
    x = x/2; //round down
  }
  for (i=0; i <= 7; i++)
    printf("%d",byte[i]);
}


void printint(int x) {
  int i;
    // dec
	printf("decimal: %5d\n", x);

    // hex
	printf("    hex: 0x%08x\n", x);

    // byte order
	unsigned char *hack = (unsigned char *)(&x); //treat is as an array of 4 chars

  // binary representation of numbers
	printf("  bytes: ");
	for (i = sizeof(int)-1; i >= 0; i--) {   // REVERSE ORDER!
		printBits(hack[i]); printf(" ");
	}
  printf("\n");

	printf("  hex:");
	for (i = sizeof(int)-1; i >= 0; i--) {   // same reverse order
		printf(" %02x", hack[i]);
	}
  printf("\n");


  int mult = 256;
  int recover = hack[0] + mult*hack[1] + mult*mult*hack[2] + mult*mult*mult*hack[3];
  printf("recovering the number = %d \n \n", recover);

}



int main () {

  int n = INT_MAX;
  printf("---------- %d -------------\n", n);
  printint(n);

  n = n+1;
  printf("---------- %d -------------\n", n);
  printint(n);

  n = n+1;
  printf("---------- %d -------------\n", n);
  printint(n);

  return 0;
}
  
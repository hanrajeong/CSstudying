#include <stdio.h>
#include <stdio.h>


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

/*
  For x = 261 = 256 + 4 + 1

  in the memory it is stored as
  00000101 <-- 4+1
  00000001 <-- 256
  00000000
  00000000

it is treated as the binary number 00000000000000000000000100000101
*/

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

  printf("11: -----------------------\n");
  int x = 0b00001011; // 2^3 + 2^1 + 2^0 = 11
  printint(x);

  printf("25: -----------------------\n");
  printint(25);

  printf("255: -----------------------\n");
  printint(255);

  printf("261: -----------------------\n");
  printint(261);


}
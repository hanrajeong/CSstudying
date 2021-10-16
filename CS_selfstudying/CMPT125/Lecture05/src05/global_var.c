#include <stdio.h>

int counter = 0;

void test_counter() {
  printf("global counter = %d\n", counter); // 0
  counter++;
  counter++;
  printf("global counter = %d\n", counter); // 2
  counter+=10;
  printf("global counter = %d\n", counter); // 12
  counter--;
  printf("global counter = %d\n", counter); // 11
  int counter = 5; // local counter - dont do it!!!
  printf("local counter = %d\n", counter);
}   


int main(void) {
  test_counter();
  printf("main: global counter = %d\n", counter);
  return 0;
}
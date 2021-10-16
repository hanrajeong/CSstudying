#include <stdio.h>


void test_static_count() {
  static int count = 0; // initialized only once!
  // do something
  printf("count = %d\n", count);
  count++;
}   

int main(void) {
  test_static_count();
  test_static_count();
  test_static_count();
  test_static_count();
  return 0;
}
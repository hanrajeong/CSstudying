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
  //function내부에서 gloabl variable을 바꿔봤자, global variable은 바뀌지 않는다. 바뀐 변수의 값은 오직 함수 내에서 불러질 때만 작동
  //외에는 원래 global에 할당 된 값으로 불려옴.
  //오직 함수의 관계로만 바꿀 수 있음. 값 할당 불가.
  //특히 global variable과 같은 변수 명을 사용하지 않도록 조심해야함.
  printf("local counter = %d\n", counter);
}   


int main(void) {
  test_counter();
  printf("main: global counter = %d\n", counter);
  return 0;
}
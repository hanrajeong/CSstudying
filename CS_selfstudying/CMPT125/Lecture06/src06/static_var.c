#include <stdio.h>


void test_static_count() {
  static int count = 0; // initialized only once!
  // do something
  printf("count = %d\n", count);
  count++;
}   

//만약 이걸 local로 선언하면, 매번 부를 때마다 여기에 0이 할당되어있을 것임.
//이걸 gloabl로 선언하려면, 다른 함수에서 사용할 때만 선언하는게 중요.
//여기서는 부를 때마다 이전 값을 기억하기 때문에 값이 다음과 같이 출력됨.
//count = 0
//count = 1
//count = 2
//count = 3

//void를 쓰고 말고는 별로 중요하지 않음. 결국 int main()과 int main(void)는 동일하게 취급하겠다.
int main(void) {
  test_static_count();
  test_static_count();
  test_static_count();
  test_static_count();
  return 0;
}
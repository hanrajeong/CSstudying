#include <stdio.h>


int main() { 

  int a = 100;
  float b = a; // Implicit Conversion
  printf("b  = %f, a = %d\n", b, a); 

  double x = 65.77; //긴 자료형에서 짧은 자료형으로 바꾸면 소숫점 아래 등은 그냥 버림 처리됨. 반올림이 아님.
  int y = (int) x; // Explicit Conversion
  printf("x  = %f, y = %d\n", x, y); 

/* converting integers types of different sizes */
 
  int i; // 4 byte integer
  short j; // 2 byte integer

  j = 999;
  i = (int) j; // ok
  printf("i  = %d, j = %d\n", i, j); 

  i = 99999;
  j = (short) i; // not safe! copies the 2 least significant bytes of i into j
  printf("i  = %d, j = %d\n", i, j); 

/* casting pointers */
  
  i = 10;
  int* ptr1 = &i;
  char* ptr2 = (char*) ptr1;  // explicit casting
  // 이부분에서 ptr1은 int에 pointer 중이었는데, 이제 char로 포인트하게 바꾼 것.
  // ptr1은 i의 값인 10이 int인걸로 생각하고 있음.
  // ptr2는 char이기 때문에 int의 4 byte 중에서 1 byte에 저장된 첫 byte의 10만 읽어올 수 있음.
  // 만약 이때 i 값이 1 byte 값보다 넘어가게 될땐 ptr2이 값이 변경될 수 있음.
  // 이 경우 ptr2 값이 랜덤하게 출력됨.
  printf("*ptr1  = %d *ptr2  = %d\n", *ptr1, *ptr2); 

  char k = 10;
  char* ptr3 = &k;
  int* ptr4 = (int*) ptr3; // what's going on here???
  // 우리는 k에 1 byte 메모리를 사용해서 10을 할당해둔 상황이라, 나머지 3byte에는 무슨 값이 저장되어있는지 모름.
  // 따라서 int로 불러와서 나머지 3byte를 사용하게 될 때는 가비지 값을 불러오게 됨.
  printf("*ptr3  = %d *ptr4  = %d\n", *ptr3, *ptr4); 

  return 0;
}
#include <stdio.h>

int main()
{
    int x = 5; // variable x has value 5
    printf("x = %d\n", x);
    int y = 7; // variable y has value 7
    printf("y = %d\n", y);

    printf("----------\n");

    int* px = &x; // px is the pointer to the location of x
    printf("The value at the address %p is %d\n", px, *px); //처음 %p는 adress를 print해줌. px는 adress를 가르키고,
    // *px를 해야지 거기 저장된 pointer의 value를 리턴하는 듯. 확인이 필요해보인다.
    int* py = &y; // py is the pointer to the location of y
    printf("The value at the address %p is %d\n", py, *py);

    printf("----------\n");

    *px = 7; // dereferencing, changing the value at the address px
    // go to this adress px and write it as 7 이란 의미
    printf("x = %d\n", x); // 결과 7을 return
    // printf("x = %ld\n", x); // 결과는 맞게 나오지만, compile할 떄 warning으로 something is wrong이라고 message줌.
    // printf("y = %ld\n", y); // 만약 숫자를 7보다 훨씬 크게, 4byte보다 크게 주면 어떻게 될지 확인 필요. compiler마다 조금씩 다른 듯.
    // 그럼 결국 long 변수와 int 변수의 적절한 선언은 안중요한건가?
    printf("px = %p\n", px); // adress를 return
    printf("*px = %d\n", *px); // 결과 7을 return?



    return 0;
} 
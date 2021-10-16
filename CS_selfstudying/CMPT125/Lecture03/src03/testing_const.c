// https://coding-chobo.tistory.com/58 이 페이지 참고해서 다시 공부 필요해보임.
// const int 랑 int const의 차이점 설명하는 부분의 예제임.

#include <stdio.h>

/* Testing the modifier const */



int main()
{
    char c = 'A';
    const char c1 = 'a'; // const must be initialized
    char const c2 = 'b'; // both 'const char' and 'char const' are allowed
//    c1 = 'c'; // not allowed
//    c2 = 'b'; // cannot change even to the same value
// byte로 생각해보면, c1 = 'a'자체의 byte는 1byte, 이게 가르키는 pointer는 4byte, 그 pointer의 adress는 다시 4byte

    char* ptr1;

    ptr1 = &c; // ok, since c is not const
    printf("%c\n", *ptr1);


    // const char 로 정의된 c1의 값은 pointer로 불러오려해도, should promise not to change the value of it.
    const char* ptr2 = &c1; // pointer to 'const char'. Ok to assign &c1
    ptr2 = &c2; // ok
    ptr2 = &c; // also ok (ptr will not be allowed to change the data)
//    *ptr2 = 'R'; // not allowed
// 다시 덮어써서 pointer를 바꾸긴 했지만, 결국 const char로 저으이했기때문에 값을 바꿀 수는 없다.
    c = 'R'; // ok


//    char* ptr3 = &c1; //  DANGEROUS! Warning from the compiler: cannot assign &c1
//    *ptr3 = 'T'; // DANGEROUS! Crash at runtime
//    printf("%c", c1);
//    printf("printing c1: %c\n", c1); => a
//    printf("printing *ptr3: %c\n\n", *ptr3); => T
//    printf("printing c1: %p\n", c1);
//    printf("printing *ptr3: %c\n\n", ptr3); => 이 두개는 같은 adress를 가르킴.
//    char** address_of_ptr3 = &ptr3;
//    printf("ptr3 lives at = %p\n", adress_of_ptr3);
// => 이 위에 두줄은 어떤 의미인지 다시봐야할듯하다.
// 만약 adress 자체를 print하고 싶으면 %p에다가 ptr3를 별표없이 넣어야함. *의 의미는 vlaue!
// ** 두개를 사용한 이유는 pointer의 pointer이기 때문에. char*의 pointer를 가르키는거라서. 두개를 사용함....

    char* const ptr4 = &c; // const_ptr must be initialized
    *ptr4 = 'D'; // ok
    printf("*ptr4 = %c\n", *ptr4);
    char e = 'E';
//    ptr4 = &e; // cannot reassign constant pointer


    const char* const ptr3 = &c1;;
//    ptr3 = &c2; // cannot reassign constant pointer

    return 0;
}

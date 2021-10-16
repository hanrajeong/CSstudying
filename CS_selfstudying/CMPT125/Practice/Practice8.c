#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일

struct Person {   // 구조체 정의
    char* name;        // 구조체 멤버 1
    int age;              // 구조체 멤버 2
    char* address;    // 구조체 멤버 3
};

int main()
{
    struct Person p1[10];     // 구조체 변수 선언

    // 점으로 구조체 멤버에 접근하여 값 할당
    // strcpy(p1.name, "hong");
    // struct Person p1;에 대해 p1.name = "hong"; 이건 불가능
    p1[0].name = "hong";
    p1[0].age = 30;
    strcpy(p1[0].address, "seoul");

    // 점으로 구조체 멤버에 접근하여 값 출력
    printf("name: %s\n", p1[0].name);       // 이름: 홍길동
    printf("age: %d\n", p1[0].age);        // 나이: 30
    printf("add: %s\n", p1[0].address);    // 주소: 서울시 용산구 한남동

    return 0;
}
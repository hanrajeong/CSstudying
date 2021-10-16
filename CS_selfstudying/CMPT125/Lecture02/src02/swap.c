#include <stdio.h>

void swap (int* a, int* b)
{
    printf("Address of *a = %p\n", a);
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
// a is just the local variable happened to copy the value there. so nothing related with the x.
// 이미 선언부터 a와 b에 value 자체를 복사해온거지, 어디서왔는지를 알려주진 않음. adress 형을 선언해도 의미가 없음. (시작부터 잘못됨)
void swap_wrong (int a, int b)
{
    printf("Address of a = %p\n", &a);
    int tmp = a;
    a = b;
    b = tmp;

}


int main()
{
    int x = 5;
    int y = 7;
    printf("x = %d, y = %d\n", x, y );

    printf("Address of x = %p\n", &x);
    swap(&x,&y);
//    swap_wrong(x,y);
    printf("x = %d, y = %d\n", x, y );

    return 0;
}

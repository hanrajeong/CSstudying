// #include <stdio.h>

// int main()
// {
//     int x = 5;
//     int y = 10;
//     printf("The sum of %d and %d is %d\n", x, y, x+y);

//     long z = 9876543210;
//     printf("printing long z = %ld\n", z);

//     int w = 9876543210; // assigned value is too large for int
//     printf("printing int w = %d\n", w); 

//     return 0;
// }

// 결과가 같은지 다른지 확인, 이유도 체크 필요 

#include <stdio.h> //include the library that knows what is pringf functin.

int main() //c언어의 경우 항상 main()으로 시작함.
{
    int x = 5;
    int y = 10;
    printf("The sum of %d and %d is %d\n", x, y, x+y);

    long z = 9876543210;
    printf("printing long z = %ld\n", z);
    // prinf("printing long z = %d/n", z) 로 하는 경우 long을 int로 print 하려해서 fail
    // long같은 경우 8byte인데 int의 경우 4byte라서 %d로 호출하는 경우 앞부분 4byte만 읽어온다.
    // 주소값처럼 나오는 것도 해석 가능해야하는데, ppt 참고 요.
    // hexadecimal, binary decimal
    // 10 a 11 b 12 c ... 15 f 16 = 10
    // ex. 3b7 -> decimal = 3x16^2 + 11x16 + 7x1
    // hexadecimal로 print하려면 put x. (?)
    
    int w = 9876543210; // assigned value is too large for int
    printf("printing int w = %d\n", w); 

    return 0;
}

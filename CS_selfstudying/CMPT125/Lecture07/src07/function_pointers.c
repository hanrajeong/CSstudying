#include <stdio.h> 

// this code is shamelessly stolen from geeksforgeeks

void add(int a, int b) 
{ 
    printf("Addition is %d\n", a+b); 
} 
void subtract(int a, int b) 
{ 
    printf("Subtraction is %d\n", a-b); 
} 
void multiply(int a, int b) 
{ 
    printf("Multiplication is %d\n", a*b); 
} 
  
int main() 
{ 
    // fun_ptr_arr is an array of function pointers 
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply}; 
    unsigned int ch, a = 15, b = 10; 
  
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n"); 
    scanf("%d", &ch); 

    //위에서 처럼 굳이 받는 대신,
    //array의 각 index에 함수가 할당 되어있다고 생각하고 하기와 같이 입, 출력할 수도 있음.
    //필요한 함수를 불러오는데 유용할 것.
    
    //printf("applying the functions to 15, 10\n");
    //(*fun_ptr_arr[0])(a,b);
    //(*fun_ptr_arr[1])(a,b);
    //(*fun_ptr_arr[2])(a,b);
  
    if (ch > 2) return 0; 
  
    (*fun_ptr_arr[ch])(a, b); 
  
    return 0; 
} 

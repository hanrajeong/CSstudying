#include <stdio.h> 

typedef struct{
  int (*fun)(int, int);
  char symbol;
} op_struct;

int add(int a, int b) { 
    return a+b;
} 
int subtract(int a, int b) { 
    return a-b; 
} 
int multiply(int a, int b) { 
    return a*b;
} 
int div(int a, int b) { 
    return a/b;
} 
int mod(int a, int b) { 
    return a%b;
} 
  
int main() 
{ 
  op_struct op_array[5];

  op_array[0].fun = add;
  op_array[0].symbol = '+';

  op_array[1].fun = subtract;
  op_array[1].symbol = '-';

  op_array[2].fun = multiply;
  op_array[2].symbol = '*';

  op_array[3].fun = div;
  op_array[3].symbol = '/';

  op_array[4].fun = mod;
  op_array[4].symbol = '%';

  int a = 15, b = 10; 

  for (int i = 0; i<5; i++)  
    printf("%d %c %d = %d\n", a, op_array[i].symbol,b,op_array[i].fun(a,b)); 
  
    return 0; 
} 

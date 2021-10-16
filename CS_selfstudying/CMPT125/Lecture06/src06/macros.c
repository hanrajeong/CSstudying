#include <stdio.h>

#define MY_FRAC 70/14 
#define SQR(a) a*a  // better to use (a)*(a)
#define PI 3.1415925  
#define COURSE_NAME "CMPT125"
#define AREA_OF_A_CIRCLE(r) PI*r*r
#define print_int(a) printf("%d\n", a); //이런식으로 연산이 아니어도 입력가능함.

int main() { 
  print_int(7);
  printf("PI = %f\n", PI);   // prints 3.1415925 
  printf("COURSE_NAME = %s\n", COURSE_NAME); // prints CMPT125 


  printf("--------------\n");
  
  float x = MY_FRAC; // replaced by float x = 70/14; 
  int y = SQR(5); // replaced by int                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       y = 5*5;     
  int z = SQR((5+2)); // replaced by int z = (5+2)*(5+2); 
  int w = SQR(5+2); // replaced by int y = 5+2*5+2; 

  printf("x = %f\n", x);
  printf("y = %d\n", y);
  printf("z = %d\n", z);
  printf("w = %d\n", w);


  printf("--------------\n");

  float radius = 4;
  float area = AREA_OF_A_CIRCLE(radius);
  printf("radius = %f, area = %f\n", radius, area);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment1.h"

// Q1
int square_cube(int a, int b) {
  // implement me
  // if a>b, function returns a^3 + b^2
  // let's put the return value as the result, and let it be integer, since the result will be only int.
  int result = 0;

  if(a > b)
  {
    result = a*a*a + b*b;
  }
  // otherwise, function returns a^2 + b^3
  else
  {
    result = a*a + b*b*b;
  }

  return result;
}


// Q2
void rotate3(int* a,int* b,int* c) {
  // implement me
  int temp = *b;
  *b = *c;
  *c = *a;
  *a = temp;
}


// Q3
int digits_to_zero(char* str) {
  // implement me
  // let's define integer count in order to return the number of digits in the string
  // we will looking through the given string like the array,
  // the index value is defined as i and it will be rotate from start to the end with 'for'
  // but it will end when it meets the end of the string, which is in C++, '\0'
  int i = 0;
  int count = 0;

  for(; str[i]!='\0'; i++)
  {
    if(str[i] >= '0' && str[i] <= '9')
    {
      count++;
      //After counting the digit of the string,
      //Let's change it with 0 as the question asked
      str[i] = '0';
    }
  }
  printf("%s", *str);
  return count;
}


// Q4
int max_abs(const int* arr, int len) {
  // implement me
  // define integer i
  // define max_num which will be stored with the maximum absolute value of given array

  int i;
  int max_num = 0;

  // Let's see the value stored in each index
  for(i = 0; i < len; i++)
  {
    // if the value stored in the index is positive and bigger than the max_num, 
    //it will automatically stored in max_num
    if(arr[i] > max_num) 
    {
      max_num = arr[i];
    }
    // otherwise, if the value of the index is negative, but have the bigger absolute value than the max_num,
    // it will automatically stored in max_num with the absolute value with the following code
    else if((-1) * arr[i] > max_num)
    {
      max_num = (-1) * arr[i];
    }
  }
  return max_num;
}


// Q5
void str_subtract_one(char* num) {
  // implement me
  // let's define integer i as the index to look through array of string
  int i = 0;
  // In C++, the last value of the string should be \0 in order to say it ends. Therefore, the index will look through
  // the given string, untill it meets \0
  // and then we will find the last index of the string and will put that value in int len
  int len = 0;
  for(;num[i]!='\0';i++)
  {
    if(num[i+1]=='\0')
    {
      len = i;
    }
  }

  if(num[len]<='9')
  {
    num[len]--;
  }
  else
  {
    num[len]==9;
    num[len-1]--;
  }
  return num;
}

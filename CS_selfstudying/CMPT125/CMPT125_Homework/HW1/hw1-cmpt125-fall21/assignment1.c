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

void str_subtract_one(char* num) {
  
  int len = strlen(num);

  // We will find from the end to the front, where there is digit that is not zero
  // After finding the index of this first non-zero digit, the digits which located at the front of the non-zero digit,
  // will not change, and the rest of the digit from the non-zero digit will change.

  int first_nonzero = len;

  for(int j=len; j>=0; j--)
  {
    if(num[j]=='0')
    {
      first_nonzero--;
    }
  }

  if(num[first_nonzero]=='9')
  {
    num[first_nonzero]='8';
  }
  else if(num[first_nonzero]=='8')
  {
    num[first_nonzero]='7';
  }
  else if(num[first_nonzero]=='7')
  {
    num[first_nonzero]='6';
  }
  else if(num[first_nonzero]=='6')
  {
    num[first_nonzero]='5';
  }
  else if(num[first_nonzero]=='5')
  {
    num[first_nonzero]='4';
  }
  else if(num[first_nonzero]=='4')
  {
    num[first_nonzero]='3';
  }
  else if(num[first_nonzero]=='3')
  {
    num[first_nonzero]='2';
  }
  else if(num[first_nonzero]=='2')
  {
    num[first_nonzero]='1';
  }
  else if(num[first_nonzero]=='1')
  {
    num[first_nonzero]='0';
  }

  // change the rest of digits after non-zero digit by -1, which is actually turned into 9, because they have 0

  for(int k=first_nonzero+1; k<=len; k++)
  {
    num[k]='9';
  }

  // However, when we do the minus 1, there is possibility that the first digit of the code can be 0
  // For example 100 - 1 = 099. Then, in order to change 099 to 99, we need to move all the digit 1 index front,
  // and then remove the last digit.
  
  if(num[0]=='0' && len>1)
  {
    for(int q=1; q<=len; q++)
    {
      num[q-1]=num[q];
    }
    num[len]='\0';
  }
}
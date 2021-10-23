#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment1.h"

// Q1
int square_cube(int a, int b) {
  int result = 0;
  if(a > b)
  {
    result = a*a*a + b*b;
  }
  else
  {
    result = a*a + b*b*b;
  }
  return result;
}


// Q2
void rotate3(int* a,int* b,int* c) {
  int temp;
  temp = *a;
  *a = *b;
  *b = *c;
  *c = temp;
}


// Q3
int digits_to_zero(char* str) {
  int len = strlen(str);
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if(str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
    {
      count++;
      str[i] = '0';
    }
    else if(str[i] == '0')
    {
      count++;
    }
  }
  return count;
}


// Q4
int max_abs(const int* arr, int len) {
  int max = arr[0];
  for (int i = 1; i < len; i++)
  {
    if(arr[i]<0)
    {
      if(max < (-1)*arr[i])
      {
        max = (-1)*arr[i];
      }
    }
    else if(max < arr[i])
    {
      max = arr[i];
    }
  }
  return max;
}



void str_subtract_one(char* num) {
  
  int len = strlen(num);

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
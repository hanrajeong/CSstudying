#include <stdio.h>

int main(void) {

  printf("-------str1-----------\n");


  char str1[10] = {'w', 'o', 'r', 'd', '\0'};
  printf("%p -- %s\n", str1, str1);
  str1[3] = 'k';
  printf("%p -- %s\n", str1, str1);
  str1[3] = 0;  // the numerical value of '\0' is 0
  printf("%p -- %s\n", str1, str1);

  printf("-------str2-----------\n");

  char str2[10] = {'w', 'o', 'r', 'd', '\0'};
  char* ptr_chr2 = str2;
  printf("%p -- %s\n", ptr_chr2, ptr_chr2);
  str2[3] = 'r';
  ptr_chr2[4] = 'y';
  ptr_chr2[5] = '\0'; // or 0 would also work
  printf("%p -- %s\n", ptr_chr2, ptr_chr2);

  printf("--------str3----------\n");

  char str3[10] = "nose"; // this init also works - equivalent to {'n','o', 's','e',0}
  printf("%p -- %s\n", str3, str3);
  str3[3] = 'k';
  printf("%p -- %s\n", str3, str3);

  printf("-------str4-----------\n");

  char str4[] = "hold";
  printf("%p -- %s\n", str4, str4);
  str4[3] = 'k';
  printf("%p -- %s\n", str4, str4);
//  str4[4] = 'z';      - UNDEFINED BEHAVIUOR
// printf("%p -- %s\n", str4, str4);
//  str4[5] = 'y'; WILL NOT COMPILE
//  str4[6] = 0;
 
 
  printf("-------str_comp-----------\n");

  char str_comp[10] = "compu0ter";
  printf("%s\n", str_comp);

  char str_comp2[10] = "compu\0ter";
  printf("%s\n", str_comp2);

 
  printf("-------str5-----------\n");

  char* str5 = "hold";
  printf("str5: %s\n", str5, str5);
//  str5[3] = 'k';

  char* str6 = "hold";

  if (str5 == str6)
    printf("str5 and str6 point to the same address\n");
  else
    printf("str5 and str6 point to different addresses\n");

    
  return 0;
}
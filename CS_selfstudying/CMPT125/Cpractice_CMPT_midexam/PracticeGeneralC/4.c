#include <stdio.h>

// int main()
// {
//   char ca = 'a';
//   char cb = 'b';

//   char* const ptr1_char = &ca;
//   char* ptr2_char = &cb;
//   ptr2_char = ptr1_char;

//   printf("%c", *ptr1_char);                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
//   printf("%c", *ptr2_char);
//   return 0;
// }

int main(){

const char c = 'a';

char* ptr_char = &c;`                                                                                                   

*ptr_char = 'B';

printf("%c", c);

return 0;

}
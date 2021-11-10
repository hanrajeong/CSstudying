#include <stdio.h>

int linear_search_rec_first(int* ar, int length, int number) {
  int result;
  if(length==1)
  {
    if(ar[0]==number)
      return 0;
    else
      return -1;
  }
  if(ar[0]==number)
    return 0;
  else
  {
    result = linear_search_rec_first(ar+1, length-1, number);
    if(result!=-1)
      return result+1;
    else
      return -1;
  }
}

// int linear_search_rec_first(int* ar, int length, int number) {
//   // implement me
  
//   int result;
//   // checking whether the moved pointer, which pointing to the new array's first element is equal to the searching number.
//   if(ar[0] == number)
//   {
//     return 0;
//   }
//   if(length == 1)
//   {
//     if(ar[0]==number)
//     {
//       return 0;
//     }
//     else
//     {
//       return -1;
//     }
//   }
//   else
//   {
//     // this part is for recursion
//     // finding the index by moving the pointer one index backward and then moving the length one step forward
//     result = linear_search_rec_first(ar + 1, length - 1, number);
//     // if the result is equal to -1, it means it fails to find the given number
//     // if not so, just adding 1 everytime during recursion, so make it to follow the index
//     // otherwise, just return -1 and finish.
//     if(result != -1) 
//     {
//       return result + 1;
//     }
//     else
//     {
//       return -1;
//     }
//   }
// }

int main()
{
  int ar1[] = {1,2,3,4,5,4,3,2,1};
  printf("%d", linear_search_rec_first(ar1, 9, 2));
}
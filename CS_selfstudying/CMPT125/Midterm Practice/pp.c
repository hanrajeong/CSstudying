#include <stdio.h>

int linear_search_rec_first(int* ar, int length, int number)
{
  int result;
  if(length <= 0)
  {
    return -1;
  }
  if(ar[0] == number)
  {
    return 0;
  }
  else
  {
    result = linear_search_rec_first(ar + 1, length - 1, number);
    if(result != -1) 
    {
      result = result + 1;
    }
    else
    {
      return -1;
    }
  }
  return result;
}


// int linear_search_rec_last(int *ar, int length, int number)
// {
//   if(length<=0)
//   {
//     return -1;
//   }
//   if(ar[length-1] == number)
//   {
//     return length-1;
//   }
//   else
//   {
//     return linear_search_rec_last(ar, length-1, number);
//   }
//   return -1;
// }

int main(void)
{
  int A[10] = {1, 5, 3, 4, 5, 6, 7, 8, 9, 10};
  int d1 = linear_search_rec_first(A, 10, 1);
  // int d2 = linear_search_rec_last(A, 10, 9);
  printf("%d", d1);

}

// char** get_tokens(const char* str, char delim) {
//   int count = count_tokens(str, delim);
//   if (count==0)
//     return NULL;
//   // assume the number of tokens is >= 1
//   char** ret = (char**) malloc(sizeof(char*)*count);
//   if (ret==NULL) {
//     // printf("malloc failed");
//     return NULL;
//   }
//   // pointer to the beginning and end of a token
//   const char* token_start = str;
//   const char* token_end;
//   // length of a token (equal to token_end-token_start)
//   int len_str_i; 
//   // create the i'th token
//   for (int i=0; i<count; i++) {
//     // find the beginning of the first token
//     while (*token_start==delim)
//       token_start++;
//     // find end of token
//     token_end = token_start+1;
//     while (*token_end != 0 && *token_end!=delim)
//       token_end++;
//     // compute the length of the token
//     // and allocate memory for the token
//     len_str_i = token_end-token_start;
//     ret[i] = (char*) malloc((len_str_i+1)*sizeof(char));
//     strncpy(ret[i], token_start, len_str_i);

//     token_start = token_end+1;
//   }

//   return ret;
// }
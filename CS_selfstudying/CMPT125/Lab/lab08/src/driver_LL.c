#include <stdio.h>
#include <stdlib.h>

#include "LL.h"


int main () {
  LL_t* list = LLcreate();
  if (list == NULL)
    return -1;

  int N = 10;
  while(N>0) {
    LL_add_to_head(list, N);
    N--;
  }
  for(N=0; N<10; N++)
    LL_add_to_tail(list, N);
  LL_print(list);

  printf("remove from head: %d\n", LL_remove_from_head(list));
  printf("remove from tail: %d\n",LL_remove_from_tail(list));
  LL_print(list);

  LL_print_reverse(list);

  LL_free(list);

  // test all other functions 

  return 0;
}

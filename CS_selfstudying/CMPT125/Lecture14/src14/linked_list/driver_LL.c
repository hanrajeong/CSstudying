#include <stdio.h>
#include <stdlib.h>

#include "LL.h"


int main () {
	LL_t* list = LLcreate();
	if (list == NULL)
		return -1;

	int N = 10;
	while(N) {
		LL_add_to_head(list, N);
		N--;
	}
	LL_print(list);
	LL_free(list);
	return 0;
}

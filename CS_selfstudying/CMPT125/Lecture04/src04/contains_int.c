#include <stdio.h>


// returns 1 if array contains elt in the first n elements
// returns 0 otherwise
int contains(const int* array, int n, int elt) {
	int found = 0;
	int i = 0;
	while (i < n && found == 0)
    {
		if (array[i] == elt)
			found = 1;
		i++;
	}
	return found;
}



int main()
{
    int ar[9] = {12, 34, 92, -2, 3, 4, 98, 132, 0};

    if (contains(ar, 9, 4) == 1)
        printf("ar contains 4\n" );
    else
        printf("ar does not contain 4\n" );

    if (contains(ar, 6, 132) == 1)
        printf("ar contains 132 in the first 6 elements\n" );
    else
        printf("ar does not contain 132 in the first 6 elements\n" );

    return 0;
}


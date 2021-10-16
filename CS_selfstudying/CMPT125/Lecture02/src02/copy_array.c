#include <stdio.h>

//copies the first n values of the array, n should not be the length of src. can be diff
//the assumption is both dest, src have at least allowed to use n numbers. n should be equal or shorter than the length.
//또한 아래서 i의 시작값을 바꿔주면 꼭 처음부터 시작하는 것은 아니니까...

void copy_array(int* dest , const int* src, int n) //바꾸지 않을 것에는 const를 써서 선언해야함. 하지만 const 안써도 안바꾸는 코드라 결론은 같음.
//여기서는 dest라는 arr에 src arr요소를 복사해다가 넣는거니까 const를 src앞에다가 선언
// int도 변경하지 않을껀데 const를 써서 선언하지 않는 이유는? : the user of the function needs this commitment
// 즉, n값은 local variable이고 user의 입장에서는 관심없음.
// 우리는 value를 pass하는거지 lenght 자체를 pass하는 것은 아니고, 때문에 n값은 변경될 수 없음.
{
    int i;

    for(i=0; i < n; i++)    {
        dest[i] = src[i];
    }
}

// returns -1 if the two arrays are equal in the first n indices
// otherwise, returns the first index where the array differ
// assumes that the sizes of both arrays is at least n
int compare_arrays(const int* array1 , const int* array2, int n)
{
  if (array1 == array2) // checking equality of the pointers
    return -1;
  
  int i;
  for (i=0; i<n; i++)
  {
      if (array1[i] != array2[i])
        return i;
  }

  return -1;
}

int main()
{
    int array1[6] = {0, 2, -4, 12, 8, 1};
    int array2[6] = {1, 2, 3, 4, 5}; // the length of array2 is 6, but only the first 5 elts are initialized

    if (compare_arrays(array1, array2, 6) == -1)
        printf("The arrays are equal\n");
    else
        printf("The arrays are not equal\n");

    copy_array(array2, array1, 6);

    if (compare_arrays(array1, array2, 6) == -1)
        printf("The arrays are equal\n");
    else
        printf("The arrays are not equal\n");
    // arrays are equal here

    printf("-----------------\n");

    array2[4] = 25;
    if (compare_arrays(array1, array2, 6) == -1)
        printf("The arrays are equal\n");
    else
        printf("The arrays are not equal\n");

    if (compare_arrays(array1, array2, 4) == -1)
        printf("The arrays are equal\n");
    else
        printf("The arrays are not equal\n");

    return 0;
}

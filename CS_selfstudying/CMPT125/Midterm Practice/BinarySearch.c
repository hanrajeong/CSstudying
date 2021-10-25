#include <stdio.h>

// int binary_search(int* ar, int len, int number) {
//   int start = 0, end = len-1, mid;
//   while (start<=end) {
// //    printf("[%d, %d]\n", start, end); // debugging
//     mid = (start+end)/2;
//     if (number==ar[mid])
//       return mid;
//     else if  (number < ar[mid])
//       end = mid-1;
//     else // id > players[mid].ID
//       start = mid+1;
//   }
//   return -1;
// }

int binary_search(int * arr, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    int m = n / 2;
    int found;
    if (arr[m] == key)
    {
        found = m;
    }
    else if (arr[m] < key)
    {
        found = binary_search(arr + m + 1, n - m - 1, key);
        if (found != -1)
        {
            found += m + 1;
        }
        else
        {
          return -1;
        }
    }
    else
    {
        found = binary_search(arr, m, key);
        if(found == -1)
        {
          return -1;
        }
    }
    return found;
}

int main(void)
{
  int arr[10] = {1, 3, 6, 8, 9, 10, 14, 18, 40, 90};

  int index = binary_search(arr, 10, 90);

  printf("%d", index);

  return 0;
}
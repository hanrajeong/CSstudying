#include <stdio.h>
#include <stdlib.h>


void merge(int* A, int n, int mid) {
// temporary array, to be released in the end
int* tmp = (int*) malloc(n*sizeof(int));
int ind1 = 0, ind2 = mid;
int i = 0;
// adding elements to the new array one at a time
// while (i < n) {
// if (ind1==mid || (ind2<n && A[ind2]<A[ind1])) {
// tmp[i] = A[ind2];
// ind2++;
// }
// else { // (ind2 == n || A[ind1] < A[ind2])
// tmp[i] = A[ind1];
// ind1++;
// }
// i++;
// }
// // copy from tmp back to A
// for (int i = 0 ; i < n; i++)
// A[i] = tmp[i];
// // free the unused memory
// free(tmp);

while(ind1<mid && ind2<n)
{
  if(A[ind1]<A[ind2])
  {
    tmp[i] = A[ind1];
    i++;
    ind1++;
  }
  else
  {
    tmp[i] = A[ind2];
    i++;
    ind2++;
  }
}
while(ind1!=mid)
{
  tmp[i] = A[ind1];
  i++;
  ind1++;
}
while(ind2!=n)
{
  tmp[i] = A[ind2];
  i++;
  ind2++;
}
for(int p = 0; p < n; p++)
{
  A[p] = tmp[p];
}

}

void merge_sort(int* A, int n) {
if (n >= 2) {
int mid = n/2;
merge_sort(A, mid);
merge_sort(A+mid, n-mid);
merge(A,n,mid);
}
}

int main(void)
{
  int a[9] = {9,7,5,3,1,2,4,6,8};

  merge_sort(a, 9);

  for(int i = 0; i < 9; i++)
  {
    printf("%d", a[i]);
  }
}
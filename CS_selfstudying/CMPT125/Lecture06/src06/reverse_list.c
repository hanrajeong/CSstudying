#include <stdio.h>
#include <stdlib.h>



int main() { 
  int n;
  printf("Enter the size of the array\n");
  scanf("%d", &n);

  char* arr = (char*) malloc (n * sizeof(char));
  if (arr == NULL)
  {
    printf("memory allocation failed\n");
    return -1;
  }
  
  printf("Enter the %d numbers\n", n);
  for (int i  = 0; i < n; i++)
    scanf("%s", &arr[i]);

 
  printf("The list in reverse order:\n");
  for (int i = n-1; i >=0; i--)
  {
    printf("%c ", arr[i]);
  }
  printf("\n");



  free(arr);
 
 return 0;
}
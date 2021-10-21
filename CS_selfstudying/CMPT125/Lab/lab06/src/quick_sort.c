#include <stdio.h>
void show(int* a, int len)
{
  for(int i = 0; i < len; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}
void quicksort(int number[25],int first,int last)
{
  int i, j, pivot, temp;
  if(first<last){
  pivot=first;
  i=first;
  j=last;
  while(i<j){
  while(number[i]<=number[pivot]&&i<last)
  i++;
  while(number[j]>number[pivot])
  j--;
  printf("%d %d\n", i, j);
  if(i<j){
  printf("swap: left, right: %d %d\n", number[i], number[j]);
  temp=number[i];
  number[i]=number[j];
  number[j]=temp;
  }
  show(number, 6);
  }
  printf("swap: pivot, right: %d %d\n", number[pivot], number[j]);
  temp=number[pivot];
  number[pivot]=number[j];
  number[j]=temp;
  show(number, 6);
  quicksort(number,first,j-1);
  quicksort(number,j+1,last);
  }
}
int main(){
int i, count, number[25];
printf("Enter some elements (Max. - 25): ");
scanf("%d",&count);
printf("Enter %d elements: ", count);
for(i=0;i<count;i++)
scanf("%d",&number[i]);
quicksort(number,0,count-1);
printf("The Sorted Order is: ");
for(i=0;i<count;i++)
printf(" %d",number[i]);
return 0;
}
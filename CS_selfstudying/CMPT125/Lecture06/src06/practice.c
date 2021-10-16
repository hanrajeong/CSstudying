#include <stdio.h>
#include <stdlib.h>
// size를 모르는 array를 어떻게 선언할 것인지에 대한 연습.

int main(void)
{
  int n;

  printf("please type the size of array: ");
  scanf("%d", &n);

  // 매번 우리가 변수를 선언할 때는 compile 할 당시에 size를 명확히 알고 있어야한다.
  // 이경우는 run할때는 N값을 받으니까 사이즈를 알 수 있지만, compile당시에는 알 수가 없기 때문에 일부 version의 C에서는 comopile이 안될 수 있음.
  // array의 길이를 엄청나게 기렉 선언하면 됨. int arr[10000000000000000]; 이런 식으로..
  // We need to do a dynamic memory allocation.
  int* arr = (int*) malloc(n*sizeof(int));

  if (n <= 0)
  {
    printf("malloc failed");
    return -1;
  }

  else
  {
    for (int i = 0; i < n; i++)
    {
      arr[i] = n - i - 1;
    }
    for (int j = 0; j < n; j++)
    {
      printf("%d ", arr[j]);
    }
    return 0;
  }


}
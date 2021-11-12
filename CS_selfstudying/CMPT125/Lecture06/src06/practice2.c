#include <stdio.h>
#include <stdlib.h>

# define TEN 10

//이떄 우리는 TEN을 local variable로 사용하고 있는 것. 때문에 함수가 닫히면 TEN의 값을 불러올수가 없음.
//따라서 함수를 이렇게 정의하면 pointer로 불러올 떄 local variable을 사용할 수 없어서 문제가 생김.
// 이렇게 쓰고 싶으면 int* ret = (int*)malloc(10 * sizeof(int)) (???)

int* get_array_of_squares_of_length_10() {
  int ret[TEN];

  for (int i = 0; i < TEN; i++)
  {
    ret[i] = i*i;
  }
  for(int i=0; i<10; i++)
    printf("%d ",ret[i]);
  return ret;
}

int main(void)
{
  int* ar = get_array_of_squares_of_length_10();

}
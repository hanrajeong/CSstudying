#include <stdio.h>
// average gets an array ar of a given length n
// and returns the average of the elements in the array

// plz make a code readable, 파이썬과 유사하게 줄을 잘 맞추기. c는 파이썬이랑 달리 context를 안맞춰도 기능함.
float average(float ar[], int n) // const float ar[], 로 바꿔도 결국 바꾸지 않을꺼니까 결론은 같음.
//const는 array안의 value를 바꾸지 않게 만들어줌 -> 바꾸지 않겠다고 선언한것.
//average만을 구하고 싶은 것임. array의 length를 알려주지는 않음. 결국 array의 legnth가 bound를 넘어가지 않게 조심해야함.
// pointer일뿐임.
{
  float sum = 0;
    int i;
    for(i=0; i < n; i++)
    {
      sum += ar[i];
    }
    
    // 이건 내가 쓴 코드
    // float average = sum / n;
    // return average;

    // 동일하게 4.550 나옴.
    return sum/n;
}

int main()
{
    float arr[6] = {0.2, 4.5, 7.1, 12.7, 4, -1.2};

    float avg = average(arr, 6);
    printf("%.3f\n", avg); //3digits of float number, 반올림. (파이썬과 유사. 정리 필요) C library를 찾아서 확인해보는거 추천.
// float* arr_ptr = arr;
// printf("avg in ptr_arr = %.3f\n", average(arr_ptr, 6))
// 질문, 만약 average에서 int n의 값이 length보다 커지면 어떻게 될까. 시간이 늘어나나? 그럼 파이썬처럼 len을 사용해야하나?


    return 0;
}

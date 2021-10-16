//함수 포인터 배열의 사용

#include <stdio.h>
int hap(int a, int b);
int cha(int a, int b);
int gob(int a, int b);
int na(int a, int b);


int main(void)
{
  int num1, num2;
  int op;

  re:
  printf("Please select the menu and type the number for your selected menu\n");
  printf("1. addition 2. Subtraction 3. Multiplication 4. Division 5. End: ");
  scanf("%d", &op);

  if(op < 1 || op > 5)
  {
    printf("Plese type only the number between 1 to five!\n");
    goto re;
  }

  if(op==5)
  {
    return 0;
  }

  int(*fp[4])(int, int) = {hap, cha, gob, na};

  printf("please enter two integers you want to calculate: ");
  scanf("%d %d", &num1, &num2);

  int result = fp[op-1](num1, num2);

  printf("The result is %d", result);

  return 0; 
}

int hap(int a, int b)
{
  int result = a + b;

  return result;
}

int cha(int a, int b)
{
  int result = a - b;

  return result;
}

int gob(int a, int b)
{
  int result = a * b;

  return result;
}

int na(int a, int b)
{
  int result = a / b;

  return result;
}
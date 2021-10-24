#include <stdio.h>
typedef struct complex {
    float real;
    float imag;
} complex;

complex result(complex n1, complex n2)
{
  complex temp;
  temp.real = n1.real + n2.real;
  temp.imag = n1.imag + n2.imag;

  return temp;
}

int main()
{
  complex n1;
  complex n2;
  printf("type the real and imag part of the complex number in order: ");
  scanf("%f %f", &n1.real, &n1.imag);
  printf("type the real and imag part of the complex number in order: ");
  scanf("%f %f", &n2.real, &n2.imag);

  complex re = result(n1, n2);

  printf("%f + %fi", re.real, re.imag);
  return 0;
}
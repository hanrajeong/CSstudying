#include <stdio.h>
#include <stdlib.h>

struct student{
  int studentnumber;
  char name[10];
  int kor;
  int eng;
  int math;
  double avg;
};

int main(void)
{
  struct student s;

  int i, sum;

  for(i=1; i<=3; i++)
  {
    printf("%d student\n", i);
    printf("Student ID number: ");
    scanf("%d", &s.studentnumber);
    printf("Name: ");
    scanf("%s", s.name, sizeof(s.name));
    printf("Korean score: ");
    scanf("%d", &s.kor);
    printf("English score: ");
    scanf("%d", &s.eng);
    printf("Math score: ");
    scanf("%d", &s.math);

    sum = s.kor + s.eng + s.math;
    s.avg = sum / 3.0;

    printf("\n%d %s %d %d %d %4.2f\n", s.studentnumber, s.name, s.kor, s.eng, s.math, s.avg);
    printf("\n");
  }

  printf("\n%d %s %d %d %d %4.2f\n", s.studentnumber, s.name, s.kor, s.eng, s.math, s.avg);

  return 0;
}
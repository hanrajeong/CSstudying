#include <stdio.h>
struct student {
    char firstName[50];
    int roll;
    float marks;
} s[5];

int main()
{
  for(int i = 0; i<5; i++)
  {
    printf("please type the name of %d person ", i);
    gets(s[i].firstName);//sizeof(s[i].firstName), ,stdin
    s[i].roll = i;
    printf("please type the marks: ");
    scanf("%f", &s[i].marks);
    getchar();
  }

  printf("Information---------------\n");
  for(int j = 0; j<5; j++)
  {
    printf("The name: %s\n", s[j].firstName);
    printf("The roll number: %d\n", s[j].roll);
    printf("The mark: %f\n", s[j].marks);
  }
}
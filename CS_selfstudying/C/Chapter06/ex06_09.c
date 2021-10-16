#include <stdio.h>

int main(void)
{
  char blood;

  printf("please enter your blood type (If your blood type is 'AB', then please type 'C') ");
  scanf("%c", &blood, sizeof(blood));

  if(blood=='A' || blood=='a')
  {
    printf("you are sweet");
  }
  else if(blood=='B' || blood=='b')
  {
    printf("you are sensitive");
  }
  else if(blood=='C' || blood=='C')
  {
    printf("you are artistic");
  }
  else if(blood=='O' || blood=='o')
  {
    printf("you are active");
  }
  else
  {
    printf("you entered wrong blood type");
  }
  return 0;
}
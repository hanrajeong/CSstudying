#include <stdio.h>

int main(void)
{
  char blood;

  printf("please enter your blood type (If your blood type is 'AB', then please type 'C') ");
  scanf("%c", &blood, sizeof(blood));

  switch(blood)
  {
    case 'A':
    case 'a':
      printf("you are sweet");
      break;

    case 'B':
    case 'b':
      printf("you are sensitive");
      break;
    
    case 'C':
    case 'c':
      printf("you are artistic");
      break;
    
    case 'O':
    case 'o':
      printf("you are active");
      break;

    default:
      printf("you typed wrong blood type");
      break;
  }
  return 0;
}
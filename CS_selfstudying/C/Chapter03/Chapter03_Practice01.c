#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char id[8];
  char pw[10];

  printf("ID(max 8 digits): ");
  scanf("%s", id, sizeof(id));

  printf("Password(max 10 digits: ");
  scanf("%s", pw, sizeof(pw));

  printf("ID : %s, PW : %s", id, pw);
  return 0;
}
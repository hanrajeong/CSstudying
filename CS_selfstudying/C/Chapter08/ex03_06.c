#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
  system("title system () function usage\n"); //실행화면 타이틀 입력

  printf("Print all the directory in the same folder with this\n");

  system("dir");
  printf("\n\nPlease type any key, and the system will be over!");
  printf("type any key: ");

  _getch();
  system("cls");
  return 0;
}
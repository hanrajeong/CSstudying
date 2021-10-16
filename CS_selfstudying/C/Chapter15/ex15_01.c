#include <stdio.h>

int main(void)
{
  FILE *fp;

  int err = fopen(&fp, "Sample.txt", "wt");

  if(0 != err)
  {
    printf("1. New File for Practice\n");
    fprintf(fp, "Happy Thanksgiving day!\n");
    fclose(fp);
  }
  else
  {
    printf("Fail to open the file");
  }
  return 0;
}
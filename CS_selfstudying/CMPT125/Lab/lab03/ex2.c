#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  float x = atof(argv[1]);
  float y = atof(argv[2]);
  float z = atof(argv[3]);
  
  float max = x;

  if(y > max)
  {
    max = y;
  }
  if(z > max)
  {
    max = z;
  }

  printf("max is %f", max);

  return 0;
}
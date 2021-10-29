#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} point;

int compare(const void* first, const void* second)
{
  point* one = (point*)first;
	point* two = (point*)second;

  int x1 = one->x;
  int y1 = one->y;
  int x2 = two->x;
  int y2 = two->y;
	if (x1*x1 + y1*y1 < x2*x2 + y2*y2)
		return -1;
	else if (x1*x1 + y1*y1 > x2*x2 + y2*y2)
		return 1;
	else
	{
		if (x1 < x2)
			return -1;
		else
			return 1;
	}
	return 0;
}


void sort_points(point* A, int length) {
  //   point A[6] = {{3,2}, {7,1}, {1,1}, {3,4}, {5,0}, {7,1}};
  qsort(A, length, sizeof(A[0]), compare);
}

int main(void)
{
  point A[6] = {{3,2}, {7,1}, {1,1}, {3,4}, {5,0}, {7,1}};

  sort_points(A,6);
//  for(int i=0;i<6;i++)
//    printf("(%d, %d) ", A[i].x, A[i].y);
//  printf("---\n");


  point correct_ans[6] = {{1,1}, {3,2}, {3,4}, {5,0}, {7,1}, {7,1}};

  bool okFlag = true;

  for (int i=0;i<6;i++)
    if (A[i].x!=correct_ans[i].x || A[i].y!=correct_ans[i].y) {
      okFlag = false;
    }

  if (okFlag)  {
    printf("Q3 ok\n");
  }
  else  {
    printf("Q3 ERROR\n");
  }
}

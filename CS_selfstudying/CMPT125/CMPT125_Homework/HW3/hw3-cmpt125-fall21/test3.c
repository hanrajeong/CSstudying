#include <stdio.h>
#include "assignment3.h"

bool test_q1_1()  {
  int a[] = {4,1,2,7,5,3,2};
  rearrange(a,7,0);
  // (4,1,2,2,5,3,7) -- swap (2,7)
  // (4,1,2,2,3,5,7) -- swap (5,3)
  // (3,1,2,2,4,5,7) -- move pivot to the right place

  bool okFlag = true;
  int correct_ans[] = {3,1,2,2,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}


bool test_q1_2()  {
  int a[] = {4,1,2,7,5,3,6};
  rearrange(a,7,4);
  // (5,1,2,7,4,3,6) -- move pivot to front
  // (5,1,2,3,4,7,6) -- swap (4,7)
  // (4,1,2,3,5,7,6) -- move pivot to the right place

  bool okFlag = true;
  int correct_ans[] = {4,1,2,3,5,7,6};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}

bool test_q1_3()  {
  int a[] = {4,1,2,7,5,3,2};
  quick_sort(a,7);
  bool okFlag = true;

  int correct_ans[] = {1,2,2,3,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}




void test_q2()  {
  point A[6] = {{3,2}, {7,1}, {1,1}, {3,4}, {5,0}, {7,1}};
//  for(int i=0;i<6;i++)
//    printf("(%d, %d) ", A[i].x, A[i].y);
//  printf("---\n");

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

// used for test Q3-find
bool is_even(int x) { return x%2; }
bool is_positive(int x) { return x>0; }

void test_q3_find()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (find(A, 6, is_even)==2 && find(A, 6, is_positive)==1) 
    printf("Q3-find ok\n");
  else
    printf("Q3-find ERROR\n");
}

// used for test Q3-map
int mult4(int x) { return x*4;}

void test_q3_map()  {
  int A[6] = {-1,3,-6,5,2,7};
  map(A, 6, mult4);

  if (A[0]==-4 && A[3]==20) 
    printf("Q3-map ok\n");
  else
    printf("Q3-map ERROR\n");
}

// used for test Q3-reduce
int sum(int x, int y) {return x+y;}
int last(int x, int y) {return y;}

void test_q3_reduce()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (reduce(A, 6, sum)==10 && reduce(A, 6, last)==7) 
    printf("Q3-reduce ok\n");
  else
    printf("Q3-reduce ERROR\n");
}



int main() {
  test_q1_1();
  test_q1_2();
  test_q1_3();
  test_q2();
  test_q3_find();
  test_q3_map();
  test_q3_reduce();
  return 0;
}
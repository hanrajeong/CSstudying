#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib/BTnode.h"
#include "sample.h"

void test_q1() { 
  int a1[] = {1,2,3,1,1};
  int a2[] = {5,2,3,1,6,10,3};
  if (contains(a1, 5, a2, 7) == true)
    printf("Q1-1 ok\n");
  else
    printf("Q1-1 ERROR\n");

  int a3[] = {1,2,3,1,1};
  int a4[] = {5,2,3,0,6,10,3};
  if (contains(a3, 5, a4, 7) == false)
    printf("Q1-2 ok\n");
  else
    printf("Q1-2 ERROR\n");
}

void test_q2() { 
  int ans1 = last_len("abcd e Fg aaBcd");
  if (ans1 == 5)
    printf("Q2 ok\n");
  else
    printf("Q2 ERROR : expected 28, return = %d\n", ans1);
}

void test_q3() { 
  BTnode_t* n1 = create_node(1);
  BTnode_t* n2 = create_node(2);
  BTnode_t* n3 = create_node(3);
  BTnode_t* n4 = create_node(4);
  BTnode_t* n5 = create_node(5);
  BTnode_t* n6 = create_node(6);
  BTnode_t* n7 = create_node(7);


  set_left_child(n1, n2);
  set_right_child(n1, n3);
//       n1
//      /  \
//    n2    n3

  set_left_child(n2,n4);
//       n1
//      /  \
//    n2    n3
//   /  
// n4   

  set_right_child(n2, n5);
//       n1
//      /  \
//    n2    n3
//   / \
// n4   n5

  set_left_child(n3, n6);
  set_left_child(n6, n7);
//       n1
//      /  \
//    n2     n3
//   / \    /
// n4  n5  n6
//        /
//      n7

  int sum = BT_sum(n1);
  if (sum==28)
    printf("Q3 ok\n");
  else
    printf("Q3 ERROR : expected 28, return = %d\n", sum);

}

int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
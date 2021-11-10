#include <stdio.h>
#include <stdlib.h>

#include "lib/BTnode.h"
 
int main(void) {
  BTnode_t* n1 = create_node(1); //linked list를 쓰는 부분.
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
//   / \    / \
// n4  n5  n6
//        /
//       n7
// 이렇게 n7의 위치를 변경하면
//preorder의 경우 1 2 4 5 3 6 7 
//inorder의 경우 4 2 5 1 7 6 3

  printf("PreOrder from 1:\n");
  print_pre_order(n1);
  printf("\n");

  printf("InOrder from 1:\n");
  print_in_order(n1);
  printf("\n");

  
  printf("\n\n------------\n\n");
  printf("computing distance between %d and %d:\n",n5->value, n7->value);
  printf("dist(%d, %d) = %d\n", n7->value, n5->value, BTdistance(n7, n5));
  printf("the size of the tree is %d\n", size(n1));
  printf("the height of the tree is %d\n", height(n1));

  return 0;
}
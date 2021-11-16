#include <stdio.h>
#include <stdlib.h>

#include "lib/BTnode.h"
 
int main(void) {
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
//  set_right_child(n3, n7);
//       n1
//      /  \
//    n2     n3
//   / \    /
// n4  n5  n6
//        /
//      n7
/*
  printf("val of root = %d\n", n1->value);
  printf("val of root->left = %d\n", n1->left->value);
  printf("val of root->right->left = %d\n", n1->right->left->value);
  printf("parent of n7  = %d\n", n7->parent->value);

  printf("size under n1 = %d\n",  size(n1));
  printf("size under n4 = %d\n",  size(n4));
*/
  printf("PreOrder from 1:\n");
  print_pre_order(n1);
  printf("\n");

  printf("InOrder from 1:\n");
  print_in_order(n1);
  printf("\n");

/*
  printf("\n\n------------\n\n");
  printf("computing distance between %d and %d:\n",n5->value, n7->value);
  printf("dist(%d, %d) = %d\n", n7->value, n5->value, BTdistance(n7, n5));
*/
  return 0;
}
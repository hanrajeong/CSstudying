#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/BTnode.h"
 
int main() {
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


/**
implement the following functions:
1) int count_leaves(BTnode_t* root);
2) int* in_order_to_array(BTnode_t* root);
3) bool are_equal(BTnode_t* root1, BTnode_t* root2);
4) BTnode_t* reconstruct_tree(int* inorder, int* preorder, int n);

Test! Test! Test!
Write more test cases and check that your solutions are correct

*/

// testing count_leaves
  printf("number of leaves in the tree is %d\n", count_leaves(n1));

// testing in_order_to_array
  int* inOrder = in_order_to_array(n1);
  int i, s;
  // s=size(n1);
  // uncomment when implemented
  // Otherwsie, the code will crash for index out of bounds
  printf("in order = [ ");
  for (i=0; i<s; i++)
    printf("%d ", inOrder[i]);
  printf("]\n");


// testing reconstruct_tree
  int inorder[] = {4,2,5,1,7,6,3};
  int preorder[] = {1,2,4,5,3,6,7};
  BTnode_t* r =reconstruct_tree(inorder, preorder, 7);
  if (are_equal(n1, r))
    printf("r is equal to n1");
  else 
    printf("r is not equal to n1");

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "BST.h"


int main() {

  BST_t* bstree = BST_create();

  BST_insert(bstree, 4);
  // 4
  BST_insert(bstree, 2);
  /*    4
  //   /
  //  2
  */
  BST_insert(bstree, 6);
  /*    4
  //   / \
  //  2   6
  */
  BST_insert(bstree, 5);
  /*    4
  //   / \
  //  2   6
  //     /
  //    5
  */
  BST_insert(bstree, 3);
  /*     4
  //   /   \
  //  2     6
  //   \   /
  //    3 5
  */
  BST_insert(bstree, 1);
  /*     4
  //   /   \
  //  2     6
  // / \   /
  //1   3 5
  */
  BST_insert(bstree, 7);
  /*     4
  //   /   \
  //  2     6
  // / \   / \
  //1   3 5   7
  */

  printf("InOrder\n");
  inOrder(bstree->root);
  printf("\n");
  
  BTnode_t* n2 = BST_find(bstree, 2);

  printf("InOrder from 2\n");
  inOrder(n2);
  printf("\n");

  return 0;
}
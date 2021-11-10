  #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 교수님이 isleaf function 추가하느라고 추가한 library. originally not given.

#include "BTnode.h"

BTnode_t* create_node(int val) {
    BTnode_t* newNode = (BTnode_t*) malloc(sizeof(BTnode_t));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

void set_left_child(BTnode_t* parent, BTnode_t* left_child) {
  if (parent)
    parent->left = left_child;
  if (left_child) // 이런식으로 if문을 넣으면 각각의 node가 NULL일 경우 코드를 실행하지 않아서 절약 가능.
    left_child->parent = parent;
}

void set_right_child(BTnode_t* parent, BTnode_t* right_child) {
  if (parent)
    parent->right = right_child;
  if (right_child)
    right_child->parent = parent;
}

bool is_leaf(BTnode_t* root)
{
  return (root->left == NULL & root->right == NULL);
}

int size(BTnode_t* root) // 교수님이랑 수업시간에 같이 썼던 함수.
{
  if(root==NULL) // what would happen if root is the only leaf, left will return 0 as it is NULL, and right will return 0 as it is NULL and +1 to count itself.
  {
    return 0;
  }
  if(is_leaf(root)) // if it is not sure about the above question, then just add the bool function.
  {
    return 1;
  }
  else
  {
    return size(root->left) + size(root->right) + 1; // +1은 해당 node를 count하는 것.
  }
}

int max(int x, int y)
{
  return x > y ? x : y;
}

int height(BTnode_t* root)
{
  if(root == NULL)
    return -1;
  // if(is_leaf(root)) // 한칸 더 내려가서 해당 node가 비어있으면 다시 -1 을 해줄꺼니까 위의 코드로도 충분함. 하지만 한단계 더 하는거니까, 차라리 해당 코드를 살리는게 더 유리하지않을까?
  //   return 0;
  else
    return max(height(root->left), height(root->right)) + 1;
}

void print_pre_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  printf("%d ", root->value);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

void print_in_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  print_in_order(root->left);
  printf("%d ", root->value);
  print_in_order(root->right);
}

void print_post_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->value);
}


void print_ancestors(BTnode_t* node, LL_t* list_of_ancestors) {
  // print the list
  printf("list of ancestors for %d:", node->value);

  LLnode_t* ancestor_LLnode = list_of_ancestors->head;
  while (ancestor_LLnode!=NULL)  
  {
    // casting from void* to BTnode_t*
    printf(" %d", ((BTnode_t*) ancestor_LLnode->data)->value);
    ancestor_LLnode = ancestor_LLnode->next; // move forward in the list
  }
  printf("\n");
}

LL_t* list_of_ancestors(BTnode_t* node) {

  LL_t* list = LLcreate();
  
  BTnode_t* current = node;
  while (current!=NULL)
  {
    LL_add_to_head(list, current); // add current vertex to the list
    current = current->parent; // go up in the tree
  }

  print_ancestors(node, list);

  return list;
}



int BTdistance(BTnode_t* n1, BTnode_t* n2) {
  // the list of ancestors has root at the beginning and n1 in the end
  LL_t* l1 = list_of_ancestors(n1);
  // the list of ancestors has root at the beginning and n2 in the end
  LL_t* l2 = list_of_ancestors(n2);

  LLnode_t* ancestor1 = l1->head;
  LLnode_t* ancestor2 = l2->head;
  int common = 0;

  printf("common ancestors: ");
  // compare the pointers to the ancestors nodes
  while ( (ancestor1->data)==(ancestor2->data) )
  {
    // casting element of the list  from void* to BTnode_t* 
    printf("%d ", ((BTnode_t*)(ancestor1->data))->value); 
    common++;
    ancestor1 = ancestor1->next; // move forward in the linked list1
    ancestor2 = ancestor2->next; // move forward in the linked list2
  }
  printf("\n");
  
  int distance = LL_size(l1) + LL_size(l2) - 2*common;
  LL_free(l1);
  LL_free(l2);
  return distance;
}



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  void* data;
  struct node* next;
} node_t;

typedef struct {
  int size;
  node_t* head;
  node_t* tail;
} LL_t;

typedef struct BTnode {
  int value;
  struct BTnode* left;
  struct BTnode* right;
  struct BTnode* parent;
} BTnode_t;

LL_t* LLcreate()
{
  LL_t* list = (LL_t*)malloc(sizeof(LL_t));
  if(list == NULL)
    return NULL;
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void LL_add_to_head(LL_t* list, void* value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = list->head;
  if((list->size)==0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->head = newNode;
  }
  (list->size)++;
}

void LL_add_to_tail(LL_t* list, void* value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = NULL;
  if(list->size == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail->next = newNode;
    list->tail = newNode;
  }
  (list->size)++;
}

void* LL_remove_from_head(LL_t* list)
{
  void* ret = list->head->data;

  list->head = list->head->next;
  (list->size)--;
  if((list->size)==0)
  {
    list->tail = NULL;
  }
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_print(LL_t* list)
{
  node_t* cur = (node_t*)malloc(sizeof(node_t));
  for(cur = list->head; cur!=NULL; cur=cur->next)
  {
    printf("%d ", cur->data);
  }
  printf("\n");
}

void LL_free(LL_t* list)
{
  node_t* cur = (node_t*)malloc(sizeof(node_t));
  while(list->head!=NULL)
  {
    cur = list->head;
    list->head = list->head->next;
    free(cur);
  }
  free(list);
}

BTnode_t* create_node(int val)
{
  BTnode_t* newNode = (BTnode_t*)malloc(sizeof(BTnode_t));
  newNode->value = val;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;
}

void set_left_child(BTnode_t* parent, BTnode_t* left_child)
{
  if(parent)
    parent->left = left_child;
  if(left_child)
    left_child->parent = parent;
}

void set_right_child(BTnode_t* parent, BTnode_t* right_child)
{
  if(parent)
    parent->right = right_child;
  if(right_child)
    right_child->parent = parent;
}

bool is_leaf(BTnode_t* root)
{
  return (root->left == NULL && root->right == NULL);
}

int size(BTnode_t* root)
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
    return 1;
  else
    return size(root->left) + size(root->right) + 1;
}

int max(int x, int y)
{
  return x>y ? x : y;
}

int height(BTnode_t* root)
{
  if(root==NULL)
    return -1;
  else
    return max(height(root->left), height(root->right)) + 1;
}

void print_in_order(BTnode_t* root)
{
  if(root==NULL)
    return;
  print_in_order(root->left);
  printf("%d ", root->value);
  print_in_order(root->right);
}

void print_pre_order(BTnode_t* root)
{
  if(root==NULL)
    return;
  printf("%d ", root->value);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

void print_post_order(BTnode_t* root)
{
  if(root==NULL)
    return;
  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->value);
}

bool common_ancestor(BTnode_t* u, BTnode_t* v)
{
  if(u==v)
    return true;
  BTnode_t* cur = u->parent;
  while(cur!=NULL)
  {
    if(cur==v)
      return true;
    cur = cur->parent;
  }
  return false;
}

int depth(BTnode_t* n)
{
  int d = 0;
  while(n!=NULL)
  {
    d++;
    n = n->parent;
  }

  return d;
}

int BTdistance(BTnode_t* n1, BTnode_t* n2)
{
  int distance = 0;
  int d1 = depth(n1);
  int d2 = depth(n2);
  if(d1<d2) // comparing the depth of the given nodes, and move the node to make them to be in the same depth.
  {
    n2=n2->parent;
    distance++; // adding the distance by 1, since we moved the node upward
  }
  else if(d1>d2)
  {
    n1=n1->parent;
    distance++;
  }
  while(n1 != NULL && n2 != NULL) 
  // after doing above, move each node to their parent's node to see
  //whether they have the same ancester.
  // Since we made them to be located in the same depth,
  // we don't have to worry about the speed of going upward.
  {
    if(n1 == n2)
    {
      return distance;
    }
    else
    {
      n1 = n1->parent;
      n2 = n2->parent;
    }
    distance += 2;
  }
  return -1;
}

int number_leaves(BTnode_t* root)
{
  if(root==NULL)
    return 0;
  if(is_leaf(root)==1)
    return 1;
  else
    return number_leaves(root->left) + number_leaves(root->right);
}

int even_nodes(BTnode_t* root)
{
  if(root == NULL)
    return 0;
  if(root->value%2 == 0)
    return even_nodes(root->left) + even_nodes(root->right) + 1;
  else
    return even_nodes(root->left) + even_nodes(root->right);
}

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

  printf("PostOrder from 1:\n");
  print_post_order(n1);
  printf("\n");

  printf("Is descendent? %d\n", common_ancestor(n1, n5));
  printf("The number of leaves are %d\n", number_leaves(n1));
  printf("The number of nodes with even values %d\n", even_nodes(n1));
  printf("\n\n------------\n\n");
  printf("computing distance between %d and %d:\n",n5->value, n7->value);
  printf("dist(%d, %d) = %d\n", n7->value, n5->value, BTdistance(n7, n5));
  printf("the size of the tree is %d\n", size(n1));
  printf("the height of the tree is %d\n", height(n1));

  return 0;
}
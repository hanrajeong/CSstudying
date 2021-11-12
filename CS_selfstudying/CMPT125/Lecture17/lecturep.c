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
  int data;
  struct BTnode* left;
  struct BTnode* right;
  struct BTnode* parent;
} BTnode_t;

typedef struct {
  LL_t* list;
} stack_t;

typedef struct {
  LL_t* list;
} queue_t;

LL_t* LL_create()
{
  LL_t* l = (LL_t*)malloc(sizeof(LL_t));
  if(l==NULL)
    return NULL;
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
  return l;
}

void LL_add_to_head(LL_t* list, void* value)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  if(newNode == NULL)
    return;
  newNode->data = value;
  newNode->next = list->head;
  if(list->size == 0)
  {
    list->tail = newNode;
  }
  list->head = newNode;
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
    list->head = newNode;
  list->tail = newNode;
  (list->size)++;
}

void* LL_remove_from_head(LL_t* list)
{
  void* ret = list->head->data;
  list->head = list->head->next;
  (list->size)--;
  return ret;
}

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  for(; cur!=NULL; cur=cur->next)
    printf("%d ", (int)cur->data);
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_free(LL_t* list)
{
  node_t* cur;
  while(cur!=NULL)
  {
    cur= list->head;
    list->head = list->head->next;
    free(cur);
  }
  free(list);
}

BTnode_t* create_node(int value)
{
  BTnode_t* b = (BTnode_t*)malloc(sizeof(BTnode_t));
  if(b==NULL)
    return NULL;
  b->data = value;
  b->left = NULL;
  b->right = NULL;
  b->parent = NULL;
  return b;
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

int max(int a, int b)
{
  if(a>b)
    return a;
  else
    return b;
}

int height(BTnode_t* root)
{
  if(root==NULL)
    return -1;
  else
    return max(height(root->left), height(root->right)) + 1;
}

stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
  if(s==NULL)
    return NULL;
  s->list = LL_create();
  return s;
}

void stack_push(stack_t* s, void* item)
{
  LL_add_to_head(s->list, item);
}

void* stack_pop(stack_t* s)
{
  return LL_remove_from_head(s->list);
}

bool stack_is_empty(stack_t* s)
{
  return LL_size(s->list)==0;
}

void stack_free(stack_t* s)
{
  LL_free(s->list);
  free(s);
}

queue_t* queue_create()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->list = LL_create();
  return q;
}

void enqueue(queue_t* q, void* item)
{
  LL_add_to_tail(q->list, item);
}

void* dequeue(queue_t* q)
{
  return LL_remove_from_head(q->list);
}

bool queue_is_empty(queue_t* q)
{
  return LL_size(q->list) == 0;
}

void print_pre_order(BTnode_t* root)
{
  if(root==NULL)
    return;
  printf("%d ", root->data);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

void nonrecursive_pre_order(BTnode_t* root)
{
  stack_t* s = stack_create();
  stack_push(s, root);
  while(!stack_is_empty(s))
  {
    BTnode_t* cur = (BTnode_t*)stack_pop(s);
    printf("%d ", cur->data);
    if(cur->right != NULL)
      stack_push(s, cur->right);
    if(cur->left != NULL) 
      stack_push(s, cur->left);
  }
}

void nonrecursive_in_order(BTnode_t* root)
{
  stack_t* s = stack_create();
  BTnode_t* cur = root;
  while(!stack_is_empty(s) || cur!=NULL)
  {
    while(cur!=NULL)
    {
      stack_push(s, cur);
      // printf("push %d\n", cur->data);
      cur = cur->left;
    }
      cur = stack_pop(s);
      printf("%d ", cur->data);
      cur= cur->right;
  }
}

void* peek(stack_t *s)
{
  if(s==NULL)
    return NULL;
  void* ret = s->list->head->data;
  return ret;
}

void nonrecursive_post_order(BTnode_t* root)
{
  stack_t* s1 = stack_create();
  stack_t* s2 = stack_create();
  BTnode_t* cur = root;
  stack_push(s1, cur);
  while(!stack_is_empty(s1))
  {
    cur = stack_pop(s1);
    stack_push(s2, cur);
    if(cur->left != NULL)
      stack_push(s1, cur->left);
    if(cur->right != NULL)
      stack_push(s1, cur->right);
  }
  while(!stack_is_empty(s2))
  {
    cur = stack_pop(s2);
    printf("%d ", cur->data);
  }
}

void print_in_order(BTnode_t* root) {
  if (root == NULL)
    return;
  print_in_order(root->left);
  printf("%d ", root->data);
  print_in_order(root->right);
}

void print_post_order(BTnode_t* root)
{
  if(root==NULL)
    return;
  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->data);
}

LL_t* list_of_ancestors(BTnode_t* node)
{
  LL_t* ret = LL_create();
  BTnode_t* cur = node;
  while(cur!=NULL)
  {
    LL_add_to_head(ret, cur);
    cur= cur->parent;
  }
  return ret;
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

  printf("PreOrder from 1:\n");
  nonrecursive_pre_order(n1);
  printf("\n");

  printf("InOrder from 1:\n");
  print_in_order(n1);
  printf("\n");
  nonrecursive_in_order(n1);
  printf("\n");

  printf("PostOrder from 1:\n");
  print_post_order(n1);
  printf("\n");
  nonrecursive_post_order(n1);
  printf("\n");


  return 0;
}



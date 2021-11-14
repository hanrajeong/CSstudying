#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  void* data;
  struct node* next;
} node_t;

typedef struct {
  node_t* head;
  node_t* tail;
  int size;
} LL_t;

typedef struct BTnode {
  int value;
  struct BTnode* left;
  struct BTnode* right;
  struct BTnode* parent;
} BTnode_t;

typedef struct{
  int len;
  LL_t* list;
} queue_t;

typedef struct {
  LL_t* list;
} stack_t;


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
  if(list->size==0)
    list->tail = NULL;
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LL_print(LL_t* list)
{
  node_t* cur = list->head;
  for(;cur!=NULL;cur=cur->next)
  {
    printf("%d ", cur->data);
  }
}

void LL_free(LL_t* list)
{
  node_t* cur = list->head;
  while(list->head != NULL)
  {
    cur = cur->next;
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
  b->value = value;
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
  return (root->left==NULL && root->right==NULL);
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
  return b;
}

int height(BTnode_t* root)
{
  if(root==NULL)
    return -1;
  else
    return max(height(root->left), height(root->right)) + 1;
}

stack_t* create_stack()
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

int stack_is_empty(stack_t* s)
{
  return (LL_size(s->list)==0);
}

void stack_free(stack_t* s)
{
  LL_free(s->list);
  free(s);
}


queue_t* create_queue()
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

int queue_is_empty(queue_t* q)
{
  return (LL_size(q->list) == 0);
}

void queue_free(queue_t* q)
{
  LL_free(q->list);
  free(q);
}

bool check_equal(BTnode_t* root1, BTnode_t* root2)
{
  if(size(root1)!=size(root2))
    return false;
  if(root1==NULL && root2==NULL)
    return true;
  if(root1->value != root2->value)
    return false;
  return check_equal(root1->left, root2->left) && check_equal(root1->right, root2->right);
}

BTnode_t* copy(BTnode_t* root)
{
  if(root==NULL)
    return NULL;
  BTnode_t* new = (BTnode_t*)malloc(sizeof(BTnode_t));
  new->left = copy(root->left);
  new->right = copy(root->right);
  new->value = root->value;
  return new;
}

void print_pre_order(BTnode_t* root) {
  if (root == NULL)
    return;  

  printf("%d ", root->value);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

BTnode_t* inorder_list(int* ar, int n)
{
  if(n<=0)
    return NULL;
  BTnode_t* new = create_node(ar[n/2]);
  new->left = inorder_list(ar, n/2);
  new->right = inorder_list(ar+(n/2)+1, n-n/2-1);
  return new;
}

int tree_size(BTnode_t* root)
{
  queue_t *q = create_queue();
  int size = 1;
  enqueue(q, root);
  while(!queue_is_empty(q))
  {
    BTnode_t* temp = (BTnode_t*)q->list->head->data;
    if(temp->left != NULL)
    {
      enqueue(q, temp->left);
      size++;
    }
    if(temp->right != NULL)
    {
      enqueue(q, temp->right);
      size++;
    }
    dequeue(q);
  }
  return size;
}

int depth(BTnode_t* root)
{
  int h = -1;
  queue_t *q = create_queue();
  enqueue(q, root);
  while(!queue_is_empty(q))
  {
    h++;
    for(int i = 0; i < LL_size(q->list); i++)
    {
      BTnode_t* temp = dequeue(q);
      if(temp->left != NULL)
        enqueue(q, temp->left);
      if(temp->right != NULL)
        enqueue(q, temp->right);
    }
  }
  return h;  
}

queue_t* same_depth_element(BTnode_t* root, int d)
{
  queue_t* q = create_queue();
  enqueue(q, root);
  for(int j = 0; j < (d-1); j++)
  {
    int len = LL_size(q->list);
    for(int i = 0; i < len; i++)
    {
      BTnode_t* temp = dequeue(q);
      // printf("%d ", temp->value);
      if(temp->left != NULL)
      {
        // printf("left is %d\n", temp->left->value);
        enqueue(q, temp->left);
      }
      if(temp->right != NULL)
      {
        // printf("right is %d\n", temp->right->value);
        enqueue(q, temp->right);
      }
    }
  }
  int l = LL_size(q->list);
  for(int i = 0; i < l; i++)
  {
    BTnode_t* te = dequeue(q);
    printf("%d ", te->value);
  }
  return q;
}

queue_t* all_inorder(int* n, int size)
{
  queue_t* q = create_queue();
  for(int i = 0; i < size; i++)
  {
    queue_t* leftsub = all_inorder(n, i);
    queue_t* rightsub = all_inorder(n+i+1, size-i-1);
    node_t* curl = leftsub->list->head;
    node_t* curr = rightsub->list->head;
    while(curl!=NULL)
    {
      while(curr!=NULL)
      {
        BTnode_t* root = (BTnode_t*)malloc(sizeof(BTnode_t));
        root->value = n[i];
        set_left_child(root, (BTnode_t*)leftsub->list->head);
        set_right_child(root, (BTnode_t*)rightsub->list->head);
        enqueue(q, root);
      }
    }
  }
  return q;
}

bool same_inorder(BTnode_t* b1, BTnode_t* b2)
{
  if(b1->value != b2->value)
    return false;
  queue_t* q1 = create_queue(); // create two queues
  queue_t* q2 = create_queue();
  enqueue(q1, b1); // put the root
  enqueue(q2, b2);
  while(!queue_is_empty(q1) && !queue_is_empty(q2))
  {
    BTnode_t* temp1 = dequeue(q1); // get the node by dequeue
    BTnode_t* temp2 = dequeue(q2);
    if(temp1->left != NULL && temp2->left != NULL && temp1->left->value == temp2->left->value)
    // if there are left child of the node and if they are same, just continue searching the other node
    {
      enqueue(q1, temp1->left);
      enqueue(q2, temp2->left);
    }
    else if(temp1->left == NULL && temp2->left == NULL)
    // if there are no left child for both, just continue
    {
      continue;
    }
    else // If their left children are not NULL but different, then just return false and end the code
      return false;
    if(temp2->right != NULL && temp2->right != NULL && temp1->right->value == temp2->right->value)
    {
      // if there are right child of the node and if they are same, continue searching the other node
      enqueue(q1, temp1->right);
      enqueue(q2, temp2->right);
    }
    else if(temp1->right == NULL && temp2->right == NULL) // If their right child are both NULL just continue;
    {
      continue;
    }
    else // If their right children are not NULL but different, then just return false and end the code
      return false;
  }
  return true;
}

void BFS(BTnode_t* root)
{
  queue_t* q = create_queue();
  enqueue(q, "*");
  enqueue(q, root);
  while(!queue_is_empty(q))
  {
    BTnode_t* cur = (BTnode_t*)dequeue(q);
    if(cur->value == '*')
      printf("* ");
    if(!queue_is_empty(q))
      enqueue(q, "*");
    else
      printf("%d ", cur->value);
    if(cur->left != NULL)
      enqueue(q, cur->left);
    if(cur->right != NULL)
      enqueue(q, cur->right);
  }
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
//inorder의 경우 4 2 5 1 3 6 7

  printf("PreOrder1:\n");
  print_pre_order(n1);
  printf("\n");

  BTnode_t* new = copy(n1);

  printf("PreOrder2:\n");
  print_pre_order(new);
  printf("\n");

  printf(check_equal(n1, new) ? "true" : "false");
  printf("\n");
  print_pre_order(new);
  printf("\n");
  // printf(same_inorder(n1, new) ? "true" : "false");
  // printf("\n");
  // BFS(new);
  int ar[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  queue_t* answer = all_inorder(ar, 10);
  while(!queue_is_empty(answer))
  {
    queue_t* temp = dequeue(answer);
    LL_print(temp->list);
  }

  // int a[7] = {4, 2, 5, 1, 6, 3, 7};
  // BTnode_t* new2 = inorder_list(a, 7);
  // printf("PreOrder3:\n");
  // print_pre_order(new2);
  // printf("\n");

  // printf("The size is %d.\n", tree_size(n1));
  // printf("The height is %d.\n", depth(n1));
  // queue_t* res = same_depth_element(n1, 3);

  // printf("InOrder from 1:\n");
  // print_in_order(n1);
  // printf("\n");

  
  // printf("\n\n------------\n\n");
  // printf("computing distance between %d and %d:\n",n5->value, n7->value);
  // printf("dist(%d, %d) = %d\n", n7->value, n5->value, BTdistance(n7, n5));
  // printf("the size of the tree is %d\n", size(n1));
  // printf("the height of the tree is %d\n", height(n1));

  return 0;
}
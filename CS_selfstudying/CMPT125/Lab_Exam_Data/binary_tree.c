#include <stdio.h>
#include <stdlib.h>
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

typedef struct {
  LL_t* list;
} stack_t;

typedef struct {
  LL_t* list;
} queue_t;


typedef struct {
  const char* name;
  int* data;
  int length;
  int capacity;
} my_array;

my_array* array_create(const char* nm, int init_size)
{
  my_array* ar = (my_array*)malloc(sizeof(my_array));
  if(ar==0)
    return NULL;
  ar->name = nm;
  ar->data = (int*)malloc(init_size*sizeof(int));
  ar->length = 0;
  ar->capacity = init_size;
  return ar;
}

int append(my_array* ar, int new_value)
{
  if(ar->length == ar->capacity)
  {
    ar->data = (int*)realloc(ar->data, (ar->capacity*1)*sizeof(int));
    (ar->capacity)++;
  }
  (ar->data)[ar->length] = new_value;
  (ar->length)++;
  return new_value;
}

int get_length(const my_array* ar)
{
  return ar->length;
}

int get(const my_array* ar, int index)
{
  return ar->data[index];
}

int set(my_array* ar, int index, int value)
{
  return ar->data[index] = value;
}

void extend(my_array* ar1, my_array* ar2)
{
  int len = get_length(ar2);
  for(int i = 0; i < len; i++)
  {
    append(ar1, get(ar2, i));
  }
}

void print_my_array(const my_array* ar) {
  for (int i=0; i<ar->length; i++)
    printf("%d ", ar->data[i]);
  printf("\n");
}

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
  if(newNode==NULL)
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

void* LL_remove_from_tail(LL_t* list)
{
  void* ret = list->tail->data;
  node_t* temp = list->head;
  while(temp->next != list->tail)
  {
    temp = temp->next;
  }
  list->tail = temp;
  list->tail->next = NULL;
  (list->size)--;
  if(list->size == 0)
    list->head = NULL;
  free(temp);
  return ret;
}

int LL_size(LL_t* list)
{
  return list->size;
}

void LLnode_free(node_t* node)
{
  free(node);
}

void LL_print(LL_t* list)
{
  node_t* cur;
  for(cur = list->head; cur!=NULL; cur=cur->next)
  {
    printf("%d ", cur->data);
  }
  printf("\n");
}

void LL_free(LL_t* list)
{
  node_t* cur;
  while(list->head != NULL)
  {
    cur = list->head;
    list->head = cur->next;
    free(cur);
  }
  free(list);
}


stack_t* stack_create()
{
  stack_t* s = (stack_t*)malloc(sizeof(stack_t));
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


queue_t* queue_create()
{
  queue_t* q = (queue_t*)malloc(sizeof(queue_t));
  if(q==NULL)
    return NULL;
  q->list = LL_create();
  if(q->list == NULL)
    return NULL;
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
  return (LL_size(q->list)==0);
}

void queue_free(queue_t* q)
{
  LL_free(q->list);
  free(q);
}

BTnode_t* create_node(int val)
{
  BTnode_t* newNode = (BTnode_t*)malloc(sizeof(BTnode_t));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;
  newNode->value = val;
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

bool is_root(BTnode_t* root)
{
  return (root->parent == NULL);
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

int size_iterative(BTnode_t* root)
{
  int size = 0;
  stack_t* s = stack_create();
  BTnode_t* cur = root;
  while(!stack_is_empty(s) || cur!=NULL)
  {
    while(cur!=NULL)
    {
      stack_push(s, cur);
      cur=cur->left;
    }
    cur = stack_pop(s);
    size++;
    cur=cur->right;
  }
  return size;
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

int depth_iterative(BTnode_t* root)
{
  int h = -1;
  queue_t* q = queue_create();
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

void same_depth_nodes(BTnode_t* root, int height)
{
  queue_t* q = queue_create();
  enqueue(q, root);
  for(int i = 0; i < height-1; i++)
  {
    for(int i = 0; i < LL_size(q->list); i++)
    {
      BTnode_t* temp = dequeue(q);
      if(temp->left != NULL)
        enqueue(q, temp->left);
      if(temp->right != NULL)
        enqueue(q, temp->right);
    }
  }
  int len = LL_size(q->list);
  for(int i = 0; i < len; i++)
  {
    BTnode_t* temp = dequeue(q);
    printf("%d ", temp->value);
  }
}

int* tree_to_array_inorder(BTnode_t* root)
{
  int* a = (int*)malloc(size(root)*sizeof(int));
  stack_t* s = stack_create();
  int i = 0;
  BTnode_t* cur = root;
  while(!stack_is_empty(s) || cur!=NULL)
  {
    while(cur!=NULL)
    {
      stack_push(s, cur);
      cur=cur->left;
    }
    cur = stack_pop(s);
    a[i++] = cur->value;
    cur=cur->right;
  }
  return a;
}

bool same_inorder(BTnode_t* root1, BTnode_t* root2)
{
  int* a1 = tree_to_array_inorder(root1);
  int* a2 = tree_to_array_inorder(root2);
  for(int i = 0; i < size(root1); i++)
  {
    if(a1[i] != a2[i])
      return false;
  }
  return true;
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

bool is_descendant(BTnode_t* u, BTnode_t* v) //v가 u의 조상인지 확인
{
  if(u==v)
    return true;
  if(u->parent == NULL)
    return false;
  BTnode_t* cur = u->parent;
  while(cur!=NULL)
  {
    if(cur==v)
      return true;
    cur=cur->parent;
  }
  return false;
}

int depth(BTnode_t* n)
{
  int d = 0;
  while(n!=NULL)
  {
    d++;
    n=n->parent;
  }
  return d;
}


int distance(BTnode_t* n1, BTnode_t* n2)
{
  int d = 0;
  int d1 = depth(n1);
  int d2 = depth(n2);
  if(d1>d2)
  {
    for(int i = 0; i<(d1-d2); i++)
    {
      d++;
      n1 = n1->parent;
    }
  }
  else if(d1<d2)
  {
    for(int i = 0; i < (d2-d1); i++)
    {
      d++;
      n2 = n2->parent;
    }
  }
  while(n1 != NULL)
  {
    if(n1 == n2)
      return d;
    n1 = n1->parent;
    n2 = n2->parent;
    d+=2;
  }
  return -1;
}

void iterative_pre_order(BTnode_t* root)
{
  stack_t* s = stack_create();
  stack_push(s, root);
  while(!stack_is_empty(s))
  {
    BTnode_t* temp = stack_pop(s);
    printf("%d ", temp->value);
    if(temp->right != NULL)
      stack_push(s, temp->right);
    if(temp->left != NULL)
      stack_push(s, temp->left);
  }
}

void iterative_in_order(BTnode_t* root)
{
  stack_t* s = stack_create();
  BTnode_t* cur = root;
  while(!stack_is_empty(s) || cur!=NULL)
  {
    while(cur!=NULL)
    {
      stack_push(s, cur);
      cur=cur->left;
    }
    cur = stack_pop(s);
    printf("%d ", cur->value);
    cur=cur->right;
  }
}

void iterative_post_order(BTnode_t* root)
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
    printf("%d ", cur->value);
  }
}

void breadth_first_search(BTnode_t* root)
{
  queue_t* q = queue_create();
  enqueue(q, root);
  while(!queue_is_empty(q))
  {
    BTnode_t* cur = dequeue(q);
    printf("%d ", cur->value);
    if(cur->left != NULL)
      enqueue(q, cur->left);
    if(cur->right != NULL)
      enqueue(q, cur->right);
  }
}

void show_cycle_BFS(BTnode_t* root)
{
  queue_t* q = queue_create();
  BTnode_t* separator = create_node(-1);
  enqueue(q, separator);
  enqueue(q, root);
  while(!queue_is_empty(q))
  {
    BTnode_t* cur = dequeue(q);
    if(cur == separator)
    {
      printf("* ");
      if(!queue_is_empty(q))
        enqueue(q, separator);
    }
    else
      printf("%d ", cur->value);
    if(cur->left != NULL)
      enqueue(q, cur->left);
    if(cur->right != NULL)
      enqueue(q, cur->right);
  }
}

int count_leaves(BTnode_t* root)
{
  if(root==NULL)
    return 0;
  if(is_leaf(root))
    return 1;
  else
    return count_leaves(root->left) + count_leaves(root->right);
}

my_array* in_order_to_array(BTnode_t* root)
{
  my_array* ar = array_create("array", size(root));
  stack_t* s = stack_create();
  BTnode_t* cur = root;
  while(!stack_is_empty(s) || cur!=NULL)
  {
    while(cur!=NULL)
    {
      stack_push(s, cur);
      cur=cur->left;
    }
    cur = stack_pop(s);
    append(ar, cur->value);
    cur=cur->right;
  }
  return ar;
}

bool are_equal(BTnode_t* root1, BTnode_t* root2)
{
  if(size(root1) != size(root2))
    return false;
  if(root1==NULL & root2==NULL)
    return true;
  if(root1->value != root2->value)
    return false;
  return are_equal(root1->left, root2->left) && are_equal(root1->right , root2->right);
}

BTnode_t* array_to_tree_same_inorder(int* ar, int n)
{
  if(n<=0)
    return NULL;
  BTnode_t* new = create_node(ar[n/2]);
  new->left = array_to_tree_same_inorder(ar, n/2);
  new->right = array_to_tree_same_inorder(ar+(n/2)+1, n-(n/2)-1);
  return new;
}

BTnode_t* array_to_tree_same_preorder(int* ar, int n)
{
  if(n<=0)
    return NULL;
  BTnode_t* new = create_node(ar[0]);
  new->left = array_to_tree_same_preorder(ar+1, (n-1)/2);
  new->right = array_to_tree_same_preorder(ar+(n-1)/2+1, n-((n-1)/2)-1);
  return new;
}

BTnode_t* array_to_tree_same_postorder(int* ar, int n)
{
  if(n<=0)
    return NULL;
  BTnode_t* new = create_node(ar[n-1]);
  new->left = array_to_tree_same_postorder(ar, (n-1)/2);
  new->right = array_to_tree_same_postorder(ar+(n-1)/2, n-(n-1)/2-1);
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

  printf("The size of this tree is %d\n", size(n1));
  printf("The size of this tree by iterative code %d\n", size_iterative(n1));

  printf("PreOrder from 1:\n");
  print_pre_order(n1);
  printf("\n");

  printf("Iterative PreOrder from 1:\n");
  iterative_pre_order(n1);
  printf("\n");

  printf("InOrder from 1:\n");
  print_in_order(n1);
  printf("\n");

  printf("Iterative InOrder from 1:\n");
  iterative_in_order(n1);
  printf("\n");

  printf("PostOrder from 1:\n");
  print_post_order(n1);
  printf("\n");

  printf("Iterative PostOrder from 1:\n");
  iterative_post_order(n1);
  printf("\n");

  printf("Breadth First Search from 1:\n");
  breadth_first_search(n1);
  printf("\n");

  printf("Show cycle BFS from 1:\n");
  show_cycle_BFS(n1);
  printf("\n");

  int array[] = {4, 2, 5, 1, 7, 6, 3};
  BTnode_t* a = array_to_tree_same_inorder(array, 7);
  printf("new same in-order BT: \n");
  print_in_order(a);
  printf("\n");

  int arr[] = {1, 2, 4, 5, 3, 6, 7};
  BTnode_t* a2 = array_to_tree_same_preorder(arr, 7);
  printf("new same pre-order BT: \n");
  print_pre_order(a2);
  printf("\n");

  int array2[] = {4, 5, 2, 7, 6, 3, 1};
  BTnode_t* a3 = array_to_tree_same_postorder(array2, 7);
  printf("new same post-order BT: \n");
  print_post_order(a3);
  printf("\n");

  printf("in order to array: \n");
  my_array* ar1 = in_order_to_array(n1);
  print_my_array(ar1);

  printf("Same depth element of level 3: \n");
  same_depth_nodes(n1, 2);
  printf("\n");

  printf("same in order tranversal? :");
  printf(same_inorder(n1, a) ? "true" : "false");
  printf("\n");

  printf("--------------------------------\n");

  printf("n1 is n2's descendent? ");
  printf(is_descendant(n2, n1) ? "true\n" : "false\n");
  // printf("Is descendent? %d\n", common_ancestor(n1, n5));
  printf("The number of leaves are %d\n", count_leaves(n1));
  // printf("The number of nodes with even values %d\n", even_nodes(n1));
  // printf("\n\n------------\n\n");
  printf("computing distance between %d and %d:\n",n5->value, n7->value);
  printf("dist(%d, %d) = %d\n", n7->value, n5->value, distance(n7, n5));
  printf("the height of the tree is %d\n", height(n1));
  printf("The height of this tree using iterative is %d\n", depth_iterative(n1));

  return 0;
}
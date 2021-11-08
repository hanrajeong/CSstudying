#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment4.h"

bool test_q1a()  {

  stack_t* s = stack_create();
  int i=0;

  for (i=0;i<100;i++) stack_push(s, i);
  int size1 = stack_size(s);

  for (i=0;i<10;i++) stack_pop(s);
  int size2 = stack_size(s);

  for (i=0;i<60;i++) stack_push(s, 'a');
  int size3 = stack_size(s);

  stack_free(s);

  if (size1==100 && size2==90 && size3==150)  {
    printf("Q1a ok\n");
    return true;
  }
  else  {
    printf("Q1a ERROR\n");
    return false;
  }
}


bool test_q1b()  {

  stack_t* s1 = stack_create();
  stack_t* s2 = stack_create();
  int i=0;

  for (i=0;i<20;i++) stack_push(s1, 'a'+i);
  for (i=0;i<20;i++) stack_push(s2, 'a'+i);
  bool is_eq1 = stack_equal(s1, s2);

  int size = stack_size(s1);

  for (i=0;i<5;i++) stack_push(s1, '0'+i);
  for (i=0;i<5;i++) stack_push(s2, '0'+i);

  bool is_eq2 = stack_equal(s1, s2);

  stack_free(s2);
  stack_free(s1);

  if (is_eq1 && is_eq2 && size==20)  {
    printf("Q1b ok\n");
    return true;
  }
  else  {
    printf("Q1b ERROR\n");
    return false;
  }
}



bool test_q1c()  {

  char str[] = "hello world";
  stack_t* s1 = stack_create();
  int i=0;
  for (i=0;i<11;i++) stack_push(s1, str[i]);
  char* ans = stack_to_string(s1);
  bool check1 = ans && strcmp(ans, str)==0;
  free(ans);

  stack_free(s1);

  if (check1)  {
    printf("Q1c ok\n");
    return true;
  }
  else  {
    printf("Q1c ERROR\n");
    return false;
  }
}



bool test_q2()  {
/***
// creates the following tree
//      +
//    /   \
//   *      +
//  / \    / \
// 3   -  5   /
//    / \    / \
//   9   7  8   -2
****/
  BTnode_t* root_plus = create_node(PLUS);
  BTnode_t* mult = create_node(MULT);
  BTnode_t* plus = create_node(PLUS);
  BTnode_t* minus = create_node(MINUS);
  BTnode_t* div = create_node(DIV);
  BTnode_t* neg_two = create_node(-2);
  BTnode_t* three = create_node(3);
  BTnode_t* five = create_node(5);
  BTnode_t* seven = create_node(7);
  BTnode_t* eight = create_node(8);
  BTnode_t* nine = create_node(9);

  set_left_child(root_plus, mult);
  set_right_child(root_plus, plus);
  
  set_left_child(mult, three);
  set_right_child(mult, minus);

  set_left_child(plus, five);
  set_right_child(plus, div);

  set_left_child(minus, nine);
  set_right_child(minus, seven);

  set_left_child(div, eight);
  set_right_child(div, neg_two);

  char* ans8 = get_arithmetic_expression(eight);
  bool check8 = (ans8 && strcmp(ans8, "8") == 0);
  if (check8)
    printf("Q2: 8 ok\n");
  else
    printf("Q2: 8 ERROR: %s\n", ans8);

  char* ans_neg_two = get_arithmetic_expression(neg_two);
  bool check_neg_two = (ans_neg_two && strcmp(ans_neg_two, "-2") == 0);
  if (check_neg_two)
    printf("Q2: -2 ok\n");
  else
    printf("Q2: -2 ERROR: %s\n", ans_neg_two);


  char* ans_minus = get_arithmetic_expression(minus);
  bool check_minus = (ans_minus && strcmp(ans_minus, "9 - 7") == 0);
  if (check_minus)
    printf("Q2: 9-7 ok\n");
  else
    printf("Q2: 9-7 ERROR: %s\n", ans_minus);

  char* ans_mult = get_arithmetic_expression(mult);
  bool check_mult = (ans_mult && strcmp(ans_mult, "3 * ( 9 - 7 )") == 0);
  if (check_mult)
    printf("Q2: 3*(9-7) ok\n");
  else
    printf("Q2: 3*(9-7) ERROR: %s\n", ans_mult);

 
  char correct_ans[] = "( 3 * ( 9 - 7 ) ) + ( 5 + ( 8 / -2 ) )";
  char* ans_root = get_arithmetic_expression(root_plus);
  bool check_rook = (ans_root && strcmp(ans_root, correct_ans) == 0);
  if (check_rook)
    printf("Q2: root ok\n");
  else
    printf("Q2: root ERROR: %s\n", ans_root);

  return true;
}

bool is_odd(int x) { return x%2==1;}

bool test_q3find()  {
/***
// creates the following tree
//      1
//    /   \
//   2     3
****/
  BTnode_t* one = create_node(1);
  BTnode_t* two = create_node(2);
  BTnode_t* three = create_node(3);
  set_left_child(one, two);
  set_right_child(one, three);
  
  BTnode_t* v = find(one, is_odd);
  if (v == one)  {
    printf("Q3-find ok\n");
    return true;
  }
  else  {
    printf("Q3-find ERROR\n");
    return false;
  }
}

int square(int x) { return x*x;}

bool test_q3map()  {
/***
// creates the following tree
//      1
//    /   \
//   2     3
****/
  BTnode_t* one = create_node(1);
  BTnode_t* two = create_node(2);
  BTnode_t* three = create_node(3);
  set_left_child(one, two);
  set_right_child(one, three);
  
  map(one, square);
  if (one->value == 1 && two->value == 4 && three->value == 9)  {
    printf("Q3-map ok\n");
    return true;
  }
  else  {
    printf("Q3-map ERROR\n");
    return false;
  }
}

bool test_q3copy()  {
/***
// creates the following tree
//      1
//    /   \
//   2     3
****/
  BTnode_t* one = create_node(1);
  BTnode_t* two = create_node(2);
  BTnode_t* three = create_node(3);
  set_left_child(one, two);
  set_right_child(one, three);
  
  BTnode_t* copy = copy_tree(one);
  if (copy && copy->left && copy->right
      && copy->parent==NULL
      && copy->left->left==NULL  && copy->left->right==NULL
      && copy->right->left==NULL  && copy->right->right==NULL
      && copy != one && copy->left != two && copy->right != three )  {
    printf("Q3-copy ok\n");
    return true;
  }
  else  {
    printf("Q3-copy ERROR\n");
    return false;
  }
}

int main() {
  test_q1a();
  test_q1b();
  test_q1c();
  test_q2();
  test_q3find();
  test_q3map();
  test_q3copy();
  return 0;
}

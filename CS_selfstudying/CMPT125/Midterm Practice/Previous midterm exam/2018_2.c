#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

typedef struct node LLnode_t;

void fun_list (LLnode_t* head){
  if(head == NULL)
  {
    printf("\n");
    return;
  }

  printf("%d ", head->data);
  if(head->next!=NULL)
    fun_list(head->next);
  printf("%d ", head->data);
}

int main(void)
{
  LLnode_t* head = (LLnode_t*)malloc(sizeof(LLnode_t));
  head->data = 1;
  head->next->data = 2;
  head->next->next->data = 3;
  fun_list(head);
}
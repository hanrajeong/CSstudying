#ifndef LL_H // we don't want things to be appear more than once,
#define LL_H // to avoid this, we define some special name, and once it is defined, let's include it. If it is already include, just ignore it.
// ifndef는 "If not defined"의 약자로서 "~을 정의(define)하지 않았다면" 이라는 뜻이다.
// LL_H를  #define 문장으로 정의하지 않았다면 아래에 등장하는 #endif 문장 이전의 내용들을 include 영역에 포함시키라는 뜻이다. 

struct node {
	int data;
	struct node * next;
};

typedef struct node  node_t;


typedef struct {
  node_t* head;
  node_t* tail;
  int size;
} LL_t;


// Creates and returns a new, empty list
LL_t * LLcreate();

// Adds a new element to the head of a list
void LL_add_to_head(LL_t* list, int value);

// Adds a new element to the tail of a list
void LL_add_to_tail(LL_t* list, int value);

// Removes the first element from a list
int LL_remove_from_head(LL_t* list);

// Returns the size of the list
int LL_size(LL_t* list);

// Outputs the list elements in order from head to tail
void LL_print(LL_t * list);


// releases the memore used by list
void LL_free(LL_t* list);


#endif

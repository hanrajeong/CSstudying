#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* name;
  int id;
} person;

// the function creates a struct person as a local var
// the struct contains char* - pointer to name and int - id
// the string with the name is allocated on the heap
person* create_person_wrong()
{
  person p;
  p.name = (char*) malloc (21*sizeof(char));
  printf("print name (up to 20 chars): ");
  scanf("%s", p.name);

  printf("print ID: ");
  scanf("%d", &(p.id));

  return &p;
}


// the function creates a struct person on heap
// the struct contains char* - pointer to name and int - id
// the string with the name is allocated on the heap (elsewhere)
person* create_person()
{
  //p를 local variable로 선언하면 안되서 malloc 함수를 이용해서 선언하게 되는 것.
  //Creating person in the global variable,
  //name이랑 id 뿐만 아니라 person이라는 data 자체가 dynamically allocate 되는 것.

  //이 예시에서는 모든 것이 heap 위에 위치하게 되는 것.
  //P가 name이랑 ID에 pointer인거지만, p 자체가 dynamically allocated 되어있고, P가 가르키는 name이랑 id가 다시 실제 이름과
  //id를 가르키는 pointer가 되는거라서, 모두가 dynammically allocated 되어있는 것.

  person* p = (person*) malloc(sizeof(person));
  p->name = (char*) malloc (21*sizeof(char));
  printf("print name (up to 20 chars): ");
  scanf("%s", p->name);

  printf("print ID: ");
  scanf("%d", &(p->id));

  return p;
}

int main(void) {
  person* people[2];
  
  printf("Person 1\n");
  people[0] = create_person();
  
  printf("\n\n");
  printf("Person 2\n");
  people[1] = create_person();

  printf("\n----------------------\n");
  printf("Person 1 name = %s, id = %d\n", people[0]->name, people[0]->id);
  printf("Person 2 name = %s, id = %d\n", people[1]->name, people[1]->id);

  for (int i=0;1<1;i++){
    free(people[i]->name);
    free(people[i]);
  }
}
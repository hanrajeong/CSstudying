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
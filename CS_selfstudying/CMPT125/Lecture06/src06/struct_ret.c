#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* name;
  int id;
} person;

// the function returns a struct person
// the struct contains char* - pointer to name and int - id
// the string with the name is allocated on the heap
person create_person()
{
  person p;
  p.name = (char*) malloc (21*sizeof(char)); // the string is allocated on the heap
  printf("print name (up to 20 chars): ");
  scanf("%s", p.name);

  printf("print ID: ");
  scanf("%d", &(p.id));

  return p;
}

int main(void) {
  person p1, p2;
  
  printf("Person 1\n");
  p1 = create_person();

  printf("\n\n");

  printf("Person 2\n");
  p2 = create_person();

  printf("\n-----------------\n");

  printf("Person 1 name = %s, id = %d\n", p1.name, p1.id);
  printf("Person 2 name = %s, id = %d\n", p2.name, p2.id);

  free(p1.name);
  free(p2.name);
  return 0;
}
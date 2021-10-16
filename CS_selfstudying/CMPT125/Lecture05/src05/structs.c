#include <stdio.h>

typedef struct student_info {
    char* first_name; // pointer is 8 bytes - the actual string will is stored somehwere else
    char* last_name;  // pointer is 8 bytes
    int id;  // 4 bytes
    int grades[5];  // 4*5 bytes
} student;


int main()
{


    student list_of_students[180];

    list_of_students[0].first_name = "Peter";
    list_of_students[0].last_name = "Parker";
    list_of_students[0].id = 99;
    list_of_students[0].grades[0] = 98;
    list_of_students[0].grades[1] = 95;

    printf("%s %s got %d on the first homework assignemnt\n ",
           list_of_students[0].first_name, list_of_students[0].last_name, list_of_students[0].grades[0]);
    
    printf("%s %s got %d on the second homework assignemnt\n ",
           list_of_students[0].first_name, list_of_students[0].last_name, list_of_students[0].grades[1]);

    printf("address of list_of_students[0] is %p\n",  &(list_of_students[0]));

    printf("that's the same as address of list_of_students: %p\n", list_of_students);

    printf("address of the pointer to first_name is %p\n",  &(list_of_students[0].first_name)); // address of the pointer


    printf("address of list_of_students[0].first_name is %p\n",  list_of_students[0].first_name); // address of the string 

    printf("address of the pointer to last_name is %p\n",  &(list_of_students[0].last_name)); // address of the pointer


    printf("address of list_of_students[0].last_name is %p\n",  list_of_students[0].last_name); // address of the string 

    printf("size of student struct is: %ld \n", sizeof(student));

    return 0;
}


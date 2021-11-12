#include <stdio.h>

typedef struct student_info {
    char* first_name;
    char* last_name;
    int id;
    int grades[5];
} student;


int main()
{

    student clark;
    student* student_ptr = &clark;

    clark.first_name = "Clark";
    (*student_ptr).last_name = "Kent";
    student_ptr->id = 123;

    printf("Name: %s %s\nID = %d\n",
        clark.first_name,
        (*student_ptr).last_name,
        student_ptr->id);
        // (*student_ptr).id);

    return 0;
}


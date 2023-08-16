#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Student;

/* typedef struct {
    char name[16];
    int age;
} Student; */ // 이 경우 deepcopy 없이도 복사됨

void deepcopyStudent(const Student* src, Student* dest);
void printStudent(const Student* s);

int main(void) {

    Student X = {.name = "lke", .age=27};
    Student Y;

    deepcopyStudent(&X, &Y);

    printStudent(&X);
    printStudent(&Y);
    
    Y.name = "lkeun";
    Y.age = 28;

    printStudent(&X);
    printStudent(&Y);

    return 0;
}

void deepcopyStudent(const Student* src, Student* dest)
{
    dest->name = malloc(strlen(src->name));
    strcpy(dest->name, src->name);
    dest->age = src->age;
}

void printStudent(const Student* s)
{
    printf("Name: %s, age: %d \n", s->name, s->age);
}
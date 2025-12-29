#include<stdio.h>

enum personType{
    teacher,
    student
};

typedef struct{
    char* name;
    int age;
    char *telephone;
    enum personType isTeacher;
}Person;

int main(){
    Person B = {.name = "abc", .age = 20, .telephone = "12345678910", .isTeacher = student};
    printf("name is : %s\n", B.name);
    printf("%d\n", B.age);

    B.name = "def";
    printf("name is : %s\n", B.name);
    Person A = B;
    printf("name is : %s\n", A.name);
    printf("%d\n", A.age);
    B.age += 2;
    Person* p = &B;
    p->age += 2;
    p->name = "cde";
    printf("name is : %s\n", B.name);
    printf("%d\n", B.age);

    Person arr[50];
    arr[25].name = "abc";
}


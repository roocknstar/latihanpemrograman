#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    int student_id;
    float gpa;
} Student;

void updateStudentInfo(Student *s, char name[], int id, float gpa);
void displayStudentInfo(Student s);

int main(){
    Student student_01;
    Student student_02;
    Student student_03;

    updateStudentInfo(&student_01, "Edward Mercer", 1001, 3.85);
    displayStudentInfo(student_01);

    printf("\nRunning Update Function\n\n");
    
    updateStudentInfo(&student_01, "Kelly Grayson", 1002, 3.95);
    displayStudentInfo(student_01);

    return 0;
}

void updateStudentInfo(Student *s, char name[], int id, float gpa){
    strcpy(s->name, name);
    s->student_id = id;
    s->gpa = gpa;
}

void displayStudentInfo(Student s){
    printf("Name: %s\n", s.name);
    printf("ID  : %d\n", s.student_id);
    printf("GPA : %.1f\n", s.gpa);
}
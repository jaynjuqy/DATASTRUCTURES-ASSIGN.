#include <stdio.h>

// Define a struct for student information
struct Student {
    char name[50];
    int age;
};

struct Grades {
    char unitcode[8];
    char unitname[50];
    float mark;
    char grade;
};

int main() {
    int ns,ng=2;
    printf("Enter number of students: ");
    scanf("%d", &ns);

    struct Student students[ns];
    struct Grades grades[ns][ng];

    for (int i = 0; i < ns; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter age: ");
        scanf("%d", &students[i].age);

        for (int j = 0; j < ng; j++) {
            printf("\nEnter the unit code: ");
            scanf("%s", &grades[i][j].unitcode);

            printf("Enter unit name: ");
            scanf("%s", &grades[i][j].unitname);

            printf("Enter grade for unit %s: ", grades[i][j].unitname);
            scanf("%f", &grades[i][j].mark);

            if(grades[i][j].mark>69){
                grades[i][j].grade='A';
            }else if(69>grades[i][j].mark>59){
                grades[i][j].grade='B';
            }else if(59>grades[i][j].mark>49){
                grades[i][j].grade='C';
            }else if(49>grades[i][j].mark>39){
                grades[i][j].grade='D';
            }else if(grades[i][j].mark<39){
                grades[i][j].grade='E';
            }

            printf("Grade for %s  is %c", grades[i][j].unitname,grades[i][j].grade);
        }
    }

    printf("\nDetails of students and their grades:\n");
    for (int i = 0; i < ns; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);

        printf("Grades:\n");
        for (int j = 0; j < ng; j++) {
            printf("Unit code: %s  Unit name: %s  mark: %.2f\n  grade: %c", grades[i][j].unitcode,grades[i][j].unitname, grades[i][j].mark
                   ,grades[i][j].grade);
        }

        printf("\n");
    }

    return 0;
}

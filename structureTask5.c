#include <stdio.h>
#include <math.h>

struct Student {
    char name[50];
    int grade;
};
struct Class {
    struct Student students[30];
    int numStudents;
};

float averageGrade(struct Class class){
    float sum = 0;
    for (int i = 0; i < class.numStudents; i++) {
        sum += class.students[i].grade;
    }
    return sum / class.numStudents;
}

int main() {
    struct Class class;
    printf("Enter the number of students in the class: ");
    scanf("%d", &class.numStudents);

    for (int i = 0; i < class.numStudents; i++) {
        printf("Name %d: ", i + 1);
        scanf("%s", class.students[i].name);
        printf("Grade %d: ", i + 1);
        scanf("%d", &class.students[i].grade);
    }

    float classAverage = averageGrade(class);
    printf("Average grade: %.2f\n", classAverage);

    return 0;
}

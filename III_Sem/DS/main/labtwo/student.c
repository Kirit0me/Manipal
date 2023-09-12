#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    char grade;
};

void readStudent(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &students[i].rollNo);
        printf("Enter grade for student %d: ", i + 1);
        scanf(" %c", &students[i].grade);
    }
}

void displayStudent(struct Student students[], int n) {
    printf("Student Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Grade: %c\n", students[i].name, students[i].rollNo, students[i].grade);
    }
}

void sortStudentByRoll(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    readStudent(students, numStudents);

    printf("\nUnsorted Student Information:\n");
    displayStudent(students, numStudents);

    sortStudentByRoll(students, numStudents);

    printf("\nSorted Student Information by Roll Number:\n");
    displayStudent(students, numStudents);

    return 0;
}


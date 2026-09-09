#include <stdio.h>
#include <string.h>

#define PROGRAM_TITLE "Student Information Management System"
#define VERSION_NUMBER "2.0"
#define PROGRAMMER_NAME "Branson Zemaitis"

enum { NUM_COURSES = 5 };

int main(void) {
    int studentID;
    char studentName[100];
    float currentGPA;
    int courseGrades[NUM_COURSES];

    printf("----------------------------------------\n");
    printf("%s\n", PROGRAM_TITLE);
    printf("Version %s\n\n", VERSION_NUMBER);
    printf("Programmer: %s\n\n", PROGRAMMER_NAME);
    printf("Welcome to SIMS\n");
    printf("----------------------------------------\n\n");

    printf("Enter Student ID: ");
    fflush(stdout);
    if (scanf("%d", &studentID) != 1) {
        printf("Error: Student ID must be a whole number (digits only, no letters).\n");
        return 1;
    }
    int idNextChar = getchar();
    if (idNextChar != '\n') {
        printf("Error: Student ID must contain only digits (no extra characters).\n");
        return 1;
    }
    if (studentID < 0) {
        printf("Error: Student ID cannot be negative.\n");
        return 1;
    }

    printf("Enter Student Name: ");
    fflush(stdout);
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0';
    if (studentName[0] == '\0') {
        printf("Error: Student Name cannot be blank.\n");
        return 1;
    }

    printf("Enter Current GPA: ");
    fflush(stdout);
    if (scanf("%f", &currentGPA) != 1) {
        printf("Error: Current GPA must be a number (no letters).\n");
        return 1;
    }
    int gpaNextChar = getchar();
    if (gpaNextChar != '\n' && gpaNextChar != EOF) {
        printf("Error: Current GPA must contain only digits and a decimal point (no extra characters).\n");
        return 1;
    }
    if (currentGPA < 0.0f || currentGPA > 4.0f) {
        printf("Error: Current GPA must be between 0.0 and 4.0.\n");
        return 1;
    }

    printf("\nStudent Summary\n\n");
    printf("Student ID : %d\n", studentID);
    printf("Student Name : %s\n", studentName);
    printf("Current GPA : %.2f\n", currentGPA);

    printf("Enter Course 1 Grade: ");
    fflush(stdout);
    if (scanf("%d", &courseGrades[0]) != 1) {
        printf("Error: Course 1 Grade must be a whole number (digits only, no letters).\n");
        return 1;
    }
    int grade1NextChar = getchar();
    if (grade1NextChar != '\n') {
        printf("Error: Course 1 Grade must contain only digits (no extra characters).\n");
        return 1;
    }
    if (courseGrades[0] < 0 || courseGrades[0] > 100) {
        printf("Error: Course 1 Grade must be between 0 and 100.\n");
        return 1;
    }

    printf("Enter Course 2 Grade: ");
    fflush(stdout);
    if (scanf("%d", &courseGrades[1]) != 1) {
        printf("Error: Course 2 Grade must be a whole number (digits only, no letters).\n");
        return 1;
    }
    int grade2NextChar = getchar();
    if (grade2NextChar != '\n') {
        printf("Error: Course 2 Grade must contain only digits (no extra characters).\n");
        return 1;
    }
    if (courseGrades[1] < 0 || courseGrades[1] > 100) {
        printf("Error: Course 2 Grade must be between 0 and 100.\n");
        return 1;
    }

    printf("Enter Course 3 Grade: ");
    fflush(stdout);
    if (scanf("%d", &courseGrades[2]) != 1) {
        printf("Error: Course 3 Grade must be a whole number (digits only, no letters).\n");
        return 1;
    }
    int grade3NextChar = getchar();
    if (grade3NextChar != '\n') {
        printf("Error: Course 3 Grade must contain only digits (no extra characters).\n");
        return 1;
    }
    if (courseGrades[2] < 0 || courseGrades[2] > 100) {
        printf("Error: Course 3 Grade must be between 0 and 100.\n");
        return 1;
    }

    printf("Enter Course 4 Grade: ");
    fflush(stdout);
    if (scanf("%d", &courseGrades[3]) != 1) {
        printf("Error: Course 4 Grade must be a whole number (digits only, no letters).\n");
        return 1;
    }
    int grade4NextChar = getchar();
    if (grade4NextChar != '\n') {
        printf("Error: Course 4 Grade must contain only digits (no extra characters).\n");
        return 1;
    }
    if (courseGrades[3] < 0 || courseGrades[3] > 100) {
        printf("Error: Course 4 Grade must be between 0 and 100.\n");
        return 1;
    }

    printf("Enter Course 5 Grade: ");
    fflush(stdout);
    if (scanf("%d", &courseGrades[4]) != 1) {
        printf("Error: Course 5 Grade must be a whole number (digits only, no letters).\n");
        return 1;
    }
    int grade5NextChar = getchar();
    if (grade5NextChar != '\n' && grade5NextChar != EOF) {
        printf("Error: Course 5 Grade must contain only digits (no extra characters).\n");
        return 1;
    }
    if (courseGrades[4] < 0 || courseGrades[4] > 100) {
        printf("Error: Course 5 Grade must be between 0 and 100.\n");
        return 1;
    }

    int gradeSum = courseGrades[0] + courseGrades[1] + courseGrades[2] + courseGrades[3] + courseGrades[4];
    float averageGrade = (float) gradeSum / NUM_COURSES;

    int highestGrade = courseGrades[0];
    if (courseGrades[1] > highestGrade) highestGrade = courseGrades[1];
    if (courseGrades[2] > highestGrade) highestGrade = courseGrades[2];
    if (courseGrades[3] > highestGrade) highestGrade = courseGrades[3];
    if (courseGrades[4] > highestGrade) highestGrade = courseGrades[4];

    int lowestGrade = courseGrades[0];
    if (courseGrades[1] < lowestGrade) lowestGrade = courseGrades[1];
    if (courseGrades[2] < lowestGrade) lowestGrade = courseGrades[2];
    if (courseGrades[3] < lowestGrade) lowestGrade = courseGrades[3];
    if (courseGrades[4] < lowestGrade) lowestGrade = courseGrades[4];

    printf("----------------------------------------\n");
    printf("Course Grades\n\n");
    printf("Course 1 : %d\n", courseGrades[0]);
    printf("Course 2 : %d\n", courseGrades[1]);
    printf("Course 3 : %d\n", courseGrades[2]);
    printf("Course 4 : %d\n", courseGrades[3]);
    printf("Course 5 : %d\n", courseGrades[4]);

    printf("\n----------------------------------------\n");
    printf("Average Grade : %.2f\n", averageGrade);
    printf("Highest Grade : %d\n", highestGrade);
    printf("Lowest Grade : %d\n", lowestGrade);

    return 0;
}

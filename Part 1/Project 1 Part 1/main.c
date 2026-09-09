#include <stdio.h>
#include <string.h>

#define PROGRAM_TITLE "Student Information Management System"
#define VERSION_NUMBER "1.0"
#define PROGRAMMER_NAME "Branson Zemaitis"

int main(void) {
    int studentID;
    char studentName[100];
    float currentGPA;

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

    return 0;
}

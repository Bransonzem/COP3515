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
    scanf("%d", &studentID);
    getchar();

    printf("Enter Student Name: ");
    fflush(stdout);
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0';

    printf("Enter Current GPA: ");
    fflush(stdout);
    scanf("%f", &currentGPA);

    printf("\nStudent Summary\n\n");
    printf("Student ID : %d\n", studentID);
    printf("Student Name : %s\n", studentName);
    printf("Current GPA : %.2f\n", currentGPA);

    return 0;
}

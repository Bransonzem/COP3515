#include <stdio.h>
#include <string.h>

#define PROGRAM_TITLE "Student Information Management System"
#define VERSION_NUMBER "3.0"
#define PROGRAMMER_NAME "Branson Zemaitis"

enum { NUM_COURSES = 5 };

/* Part 3: the four academic standing categories the Registrar defined.
 *
 * Why an enum instead of just printing text inside the if/else chain?
 *   1. An enum IS an integer type under the hood (HONORS is 0, GOOD is 1,
 *      and so on). That matters below, because a C switch statement can
 *      only test an integer - it cannot test a float. See the switch in
 *      the Student Summary section for the full explanation.
 *   2. It separates the DECISION (which category does this GPA fall into)
 *      from the DISPLAY (what words do we print). If the Registrar later
 *      changes the wording from "Honors" to "Dean's List", only the switch
 *      changes, not the classification logic.
 *   3. It answers the spec's Question for the Customer #10 - standing is
 *      represented internally as a predefined category, not loose text.
 */
enum AcademicStanding {
    STANDING_HONORS,
    STANDING_GOOD,
    STANDING_PROBATION,
    STANDING_SUSPENSION
};

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
    /* Part 3: the GPA range check below already existed in Part 1. The spec
     * requires the GPA to be validated BEFORE any standing is determined, so
     * this check stays exactly where it is - above the classification. Only
     * the wording of the message changed, to match the spec's Example 5.
     *
     * The program exits here rather than asking again. Re-prompting would
     * need a loop, and loops are not on this part's permitted feature list.
     * "Try again" means running the program again.
     */
    if (currentGPA < 0.0f || currentGPA > 4.0f) {
        printf("ERROR\n");
        printf("Invalid GPA entered.\n");
        printf("GPA must be between 0.00 and 4.00.\n");
        return 1;
    }

    /* Part 3: classify the GPA into an academic standing.
     *
     * The Registrar's published bands are:
     *     3.50 - 4.00  Honors
     *     2.00 - 3.49  Good Standing
     *     1.00 - 1.99  Academic Probation
     *     0.00 - 0.99  Academic Suspension
     *
     * Notice those bands have GAPS. Nothing covers a GPA of 3.495, which sits
     * between the top of "Good Standing" (3.49) and the bottom of "Honors"
     * (3.50). The bands were clearly written assuming two decimal places.
     *
     * Rather than test both ends of every band (>= 2.00 && <= 3.49), which
     * would leave those gaps unhandled, this uses a CASCADE of lower bounds
     * only. Each else-if is only reached when every test above it already
     * failed, so "else if (gpaRounded >= 2.00f)" already implies the GPA is
     * below 3.50 - no upper bound needed. Every valid GPA from 0.00 to 4.00
     * lands in exactly one category, and the band limits are inclusive.
     *
     * The final else is safe: the range check above already rejected anything
     * below 0.00, so by the time we reach it the GPA must be 0.00 to 0.99.
     */
    /* BUG FOUND DURING TESTING (2026-09-16), fixed here.
     *
     * The report used to print the GPA rounded to two decimals (%.2f, carried
     * over from Part 1) but classify using the raw unrounded value. Those two
     * can disagree. Entering 1.999 printed:
     *
     *     Current GPA : 2.00
     *     Academic Standing : Academic Probation
     *
     * which contradicts itself - 2.00 is Good Standing. The display rounded
     * up across the band edge while the classification did not.
     *
     * Fix: round the GPA to two decimals ONCE, into gpaRounded, then use that
     * same value for both the classification below and the display in the
     * Student Summary. Because both now read the same variable, the printed
     * GPA and the printed standing can never disagree.
     *
     * How the rounding works: multiply by 100 to shift the two decimals up
     * (1.999 -> 199.9), add 0.5 so the cast rounds to nearest instead of
     * chopping off (200.4), cast to int to drop the remainder (200), then
     * divide by 100.0f to shift back (2.00). The cast is the same technique
     * already used for the average grade in Part 2. Adding 0.5 is safe here
     * because the range check above already rejected every negative GPA.
     */
    float gpaRounded = ((int) (currentGPA * 100.0f + 0.5f)) / 100.0f;

    enum AcademicStanding standing;

    if (gpaRounded >= 3.50f) {
        standing = STANDING_HONORS;
    } else if (gpaRounded >= 2.00f) {
        standing = STANDING_GOOD;
    } else if (gpaRounded >= 1.00f) {
        standing = STANDING_PROBATION;
    } else {
        standing = STANDING_SUSPENSION;
    }

    printf("\nEnter Course 1 Grade: ");
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

    printf("\nStudent Summary\n\n");
    printf("Student ID : %d\n", studentID);
    printf("Student Name : %s\n", studentName);
    printf("Current GPA : %.2f\n", gpaRounded);

    /* Part 3: print the academic standing directly under Current GPA.
     *
     * THE KEY POINT - why does this switch test "standing" and not
     * "currentGPA"?
     *
     * Because writing switch (currentGPA) WILL NOT COMPILE. A C switch
     * requires an integer expression, and currentGPA is a float. There is no
     * way around that; it is a rule of the language, not a style choice.
     * (It makes sense if you think about it: a switch matches one exact
     * value per case, and floats are stored as approximations, so "exactly
     * equal to 3.5" is not something you can safely test.)
     *
     * So the work is split in two. The if/else cascade above did the part a
     * switch cannot do - comparing a float against RANGES. It boiled the GPA
     * down to one of four whole-number enum values. This switch then does
     * what a switch is good at: picking one of a few known integer values and
     * printing the matching text.
     *
     * The label is printed in two pieces - the "Academic Standing : " prefix
     * first, then whichever word the switch selects - so the column lines up
     * with the rows above it without repeating the prefix four times.
     */
    printf("Academic Standing : ");
    switch (standing) {
        case STANDING_HONORS:
            printf("Honors\n");
            break;
        case STANDING_GOOD:
            printf("Good Standing\n");
            break;
        case STANDING_PROBATION:
            printf("Academic Probation\n");
            break;
        case STANDING_SUSPENSION:
            printf("Academic Suspension\n");
            break;
    }

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

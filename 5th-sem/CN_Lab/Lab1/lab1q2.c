/*Write a C program to assign values to each member of the following structure.
Pass the populated structure to a function Using call-by-value and another
function using call-by-address and print the value of each member of the
structure.
struct student_info{
int roll_no;
char name [50];
float CGPA;
struct dob age;
};*/

#include <stdio.h>
#include <string.h>
struct dob
{
    int day;
    int month;
    int year;
};

struct student_info
{
    int roll;
    char name[50];
    float CGPA;
    struct dob age;
};

// Function using call-by-value
void printStudentInfoByValue(struct student_info stud)
{
    printf("Call-by-value function:\n");
    printf("Roll No: %d\n", stud.roll);
    printf("Name: %s\n", stud.name);
    printf("CGPA: %.2f\n", stud.CGPA);
    printf("Date of Birth: %d/%d/%d\n", stud.age.day, stud.age.month, stud.age.year);
}

// Function using call-by-address
void printStudentInfoByAddress(struct student_info *stud)
{
    printf("Call-by-address function:\n");
    printf("Roll No: %d\n", stud->roll);
    printf("Name: %s\n", stud->name);
    printf("CGPA: %.2f\n", stud->CGPA);
    printf("Date of Birth: %d/%d/%d\n", stud->age.day, stud->age.month, stud->age.year);
}

int main()
{
    struct student_info student1;

    // Assigning values to the members of the structure
    student1.roll = 21051698;
    strcpy(student1.name, "Vatsal Saxena");
    student1.CGPA = 9.81;
    student1.age.day = 10;
    student1.age.month = 03;
    student1.age.year = 2004;

    // Printing stud information using call-by-value
    printf("Original stud information:\n");
    printStudentInfoByValue(student1);

    // Printing stud information using call-by-address
    printf("\n");
    printStudentInfoByAddress(&student1);

    return 0;
}

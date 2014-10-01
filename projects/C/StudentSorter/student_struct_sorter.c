/******************************************************************************
Creator: IHL <axionike@gmail.com>
Created: 20140929
Last edited: 20140929

Program name: student_struct_sorter.c

Program purpose:
This program is designed to prompt user for various pieces of information about a number of students; sort the students alphabetically, by student number, and GPA; and return a sorted list according to which field is selected. This will have the same functionality as student_sorter, but utilizes a user defined struct to organize the information.

Custom structure:
typedef struct{
	char name[MAX_STUDENT_NAME_LENGTH];
	double gpa;
	int id;
} student_t;

Functions:
int numberOfStudents(void)
void getData(student_t student[], int num)

int main(void)



******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 10		/* maximum number of students allowed as input */
#define MAX_STUDENT_NAME_LENGTH 31	/* maximum size of student name (plus one space for null characters */

/*
	This program requires three different variables to be associated with each student:
	1) The GPA is any double between 0.0 and 4.0
	2) The ID number is any int > 0
	3) The name is any string which cannot exceed 30 characters
*/
typedef struct{
	char name[MAX_STUDENT_NAME_LENGTH];
	double gpa;
	int id;
} student_t; // should probably come up with more descriptive struct name

/******************************************************************************
Function:	numberOfStudents
Purpose:	This function prompts the user for the number of students, and checks validity defined by MAX_STUDENTS
Inputs:		None
Outputs:	Returns an integer "num" - entered by user
Side effects:	None
******************************************************************************/

int numberOfStudents(void) {
	int num, result;
	char line[256];

	do {
		printf("Enter the number of students>");
		if (fgets(line, sizeof(line), stdin)) {
			result = sscanf(line, "%d", &num);
			if ((result != 1) || (num <= 0) || (num > 10)) {
				printf("Invalid input, must be a positive integer from 1 to 10.\n");
			}
		}
	} while ((result != 1) || (num <= 0) || (num > 10)); // max number of students is 10
	return(num);
}

void getData(student_t student[], int num) {
	int i,
		studentNumber,
		result;

	studentNumber = 1;
	for (i=0; i<num; i++) {
		printf("Enter name of student #%d>", studentNumber);
		fflush(stdin);
		scanf("%s", student[i].name);

	/* prompt user for student number and check validity */
		do {
			printf("Enter student number for student #%d>", studentNumber);
			if (fgets(line, sizeof(line), stdin)) {
				result = sscanf(line, "%d", &(student[i].id));
				if ((result != 1) || (student[i].id <= 0)) {
					printf("Invalid input, student ID number must be a positive integer.\n");
				}
			}
		} while ((result != 1) || (student[i].id <= 0));

	/* prompt user for GPA and check validity */
		do {
			printf("Enter GPA for student #%d>", studentNumber);
			if (fgets(line, sizeof(line), stdin)) {
				result = sscanf(line, "%lf", &(student[i].gpa));
				if ((result != 1) || (student[i].gpa < 0.0) || (student[i].gpa > 4.0)) {
					printf("Invalid input, GPA must be a number between 0.0 and 4.0\n");
				}
			}
		} while ((result != 1) || (student[i].gpa < 0.0) || (student[i].gpa > 4.0));

		// iterate student number
		studentNumber += 1;
	}
}

// void sortStudents(


int main(void) {
	student_t student[MAX_STUDENTS];

	int num,
		result,
		menu;

	num = numberOfStudents();
	printf("The program executed correctly if the number of students you entered was: %d ", num);
}
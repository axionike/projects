/******************************************************************************
Creator: IHL <axionike@gmail.com>
Created: 20140929
Last edited: 20140929

Program name: student_struct_sorter.c

Program purpose: 	
This program is designed to prompt user for various pieces of information about a number of students; sort the students alphabetically, by student number, and GPA; and return a sorted list according to which field is selected. This will have the same functionality as student_sorter, but utilizes a user defined struct to organize the information.

Functions:


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
	} while ((result != 1) || (num <= 0) || (num > 10));
	return(num);
}

int main(void) {
	student_t student[MAX_STUDENTS];
	
	int num,
		result,
		menu;
		
	num = numberOfStudents();
	printf("The program executed correctly if the number of students you entered was: %d ", num);
}
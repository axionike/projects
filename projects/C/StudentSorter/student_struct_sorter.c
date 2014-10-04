/**************************************************************************************************
Program name: student_struct_sorter.c
Creator: IHL <axionike@gmail.com>
Created: 20140929

Program purpose:
This program is designed to prompt user for various pieces of information about a number of students; sort the students alphabetically, by student number, and GPA; and return a sorted list according to which field is selected. This will have the same functionality as student_sorter, but utilizes a user defined struct to organize the information.

Custom structure:
typedef struct{
	char name[MAX_STUDENT_NAME_LENGTH];
	double gpa;
	int id;
} StudentStruct;

Functions:
int numberOfStudents(void)
void getStudentData(StudentStruct student[], int num)
void printInfo(StudentStruct student[], int num)
void alphabetSort(StudentStruct student[], int num)
void idnumberSort(StudentStruct student[], int num)
void gpaSort(StudentStruct student[], int num)
void exitMenu(void)
void printMenu(void)
int main(void)
**************************************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 10				// maximum number of students allowed as input
#define MAX_STUDENT_NAME_LENGTH 31	// maximum size of student name (plus one space for null characters


/**************************************************************************************************
	This program requires three different variables to be associated with each student:
	1) The GPA is any double between 0.0 and 4.0
	2) The ID number is any int > 0
	3) The name is any string which cannot exceed 30 characters
**************************************************************************************************/
typedef struct{
	char name[MAX_STUDENT_NAME_LENGTH];
	double gpa;
	int id;
} StudentStruct;


/**************************************************************************************************
Function:	numberOfStudents
Purpose:	This function prompts the user for the number of students, and checks validity defined by MAX_STUDENTS
Inputs:		None
Outputs:	Returns an integer "num" - entered by user
Side effects:	None
**************************************************************************************************/
int numberOfStudents(void) {
	int num, userinput;
	char line[MAX_STUDENT_NAME_LENGTH];

	do {
		printf("Enter the number of students>");
		if (fgets(line, sizeof(line), stdin)) {
			userinput = sscanf(line, "%d", &num);
			if ((userinput != 1) || (num <= 0) || (num > 10)) {
				printf("Invalid input, must be a positive integer from 1 to 10.\n");
			}
		}
	} while ((userinput != 1) || (num <= 0) || (num > 10)); // max number of students is 10
	return(num);
}

/**************************************************************************************************
Function:	getStudentData
Purpose:	This function gets the information from the user and checks for valid responses.
Inputs:		(1) int num - determines how many times the function will loop
			(2) ptr to StudentStruct student[] array - storing student information
Outputs:	None
Side effects:	StudentStruct student[] array in "main" is directly accessed and modified
**************************************************************************************************/

void getStudentData(StudentStruct student[], int num) {
	int i,
		numstudents,
		userinput;
	char line[MAX_STUDENT_NAME_LENGTH];

	numstudents = 1;
	for (i=0; i<num; i++) {
		do {
			printf("Enter name of student #%d>", numstudents);
			if (fgets(line, sizeof(line), stdin)) {
				userinput = sscanf(line, "%30c", &(student[i].name));
				if (userinput != 1) {
					printf("Invalid input, please re-enter student name.\n");
				}
			}
		} while (userinput != 1);

	/* prompt user for student number and check validity */
		do {
			printf("Enter student number for student #%d>", numstudents);
			if (fgets(line, sizeof(line), stdin)) {
				userinput = sscanf(line, "%d", &(student[i].id));
				if ((userinput != 1) || (student[i].id <= 0)) {
					printf("Invalid input, student ID number must be a positive integer.\n");
				}
			}
		} while ((userinput != 1) || (student[i].id <= 0));

	/* prompt user for GPA and check validity */
		do {
			printf("Enter GPA for student #%d>", numstudents);
			if (fgets(line, sizeof(line), stdin)) {
				userinput = sscanf(line, "%lf", &(student[i].gpa));
				if ((userinput != 1) || (student[i].gpa < 0.0) || (student[i].gpa > 4.0)) {
					printf("Invalid input, GPA must be a number between 0.0 and 4.0\n");
				}
			}
		} while ((userinput != 1) || (student[i].gpa < 0.0) || (student[i].gpa > 4.0));
		numstudents += 1;
	}
}

/**************************************************************************************************
Function:	printInfo
Purpose:	Prints out student information as it is organized in array.
Inputs:		(1) int num - how many times loop will repeat
			(2) ptr to StudentStruct student[] array - storing student information
Outputs:	None
Side effects:	StudentStruct student[] array in "main" is directly accessed and modified
**************************************************************************************************/

void printInfo(StudentStruct student[], int num) {
	int i;	// loop counter

	for(i=0; i<num; i++) {
		printf("Student name:	%s\n", student[i].name);
		printf("ID number:		%d\n", student[i].id);
		printf("GPA:			%f\n", student[i].gpa);
		printf("\n");
	}
}

/**************************************************************************************************
Function:	alphabetSort
Purpose:	Sorts student[] by name field utilizing standard sort, STRCMP function to compare.
Inputs:		(1) int num - how many times loop will repeat
			(2) ptr to StudentStruct student[] array - directly modifies
Outputs:	None
Side effects:	StudentStruct student[] array in "main" is directly accessed and modified
**************************************************************************************************/

void alphabetSort(StudentStruct student[], int num) {
	int i,			// number of passes to do
		pass,		// how many times array has been passed through
		sorted,		// array sorted flag
		compare;		// strcmp result

	StudentStruct temp;	// temporary storage for sort swap

	pass=1;
	do{
		sorted=1;		// assume arrays are sorted until unordered pair is found
		for(i=0; i < num-pass; i++) {
			compare = strcmp(student[i].name, student[i+1].name);
			if(compare > 0) {
				temp = student[i];
				student[i] = student[i+1];
				student[i+1] = temp;

				sorted = 0;
			}
		}
		pass++;
	} while(!sorted);
}

/**************************************************************************************************
Function:	idnumberSort
Purpose:	Sorts student[] by student ID number
Inputs:		(1) int num - how many times loop will repeat
			(2) ptr to StudentStruct student[] array - directly modifies
Outputs:	None
Side effects:	StudentStruct student[] array in "main" is directly accessed and modified
**************************************************************************************************/

void idnumberSort(StudentStruct student[], int num) {
	int i,
		pass,
		sorted;
	char line[MAX_STUDENT_NAME_LENGTH];
	StudentStruct temp;
	int userinput,
		submenu;	// ascending or descending order

	pass=1;

	do{
		printf("--SUBMENU OPTIONS:--\n");
		printf("1) Ascending order\n");
		printf("2) Descending order\n");
		printf("Choose option: ");

		if (fgets(line, sizeof(line), stdin)) {
			userinput = sscanf(line, "%d", &submenu);
			if ((userinput != 1) && (userinput != 2)) {
				printf("Invalid input, please select one of the two choices.\n");
			}
		}
	} while ((userinput != 1) && (userinput != 2));

	if(submenu == 1) { // sort ascending
		do{
			sorted=1;		// assume arrays are sorted until unordered pair is found

			for(i=0; i < num-pass; i++) {
				if(student[i].id > student[i+1].id) {
					temp = student[i];
					student[i] = student[i+1];
					student[i+1] = temp;
					sorted = 0;
				}
			}
			pass++;
		} while(!sorted);
	}
	else { // sort descending
		pass=1;
		do{
			sorted=1;		// assume arrays are sorted until unordered pair is found

			for(i=0; i < num-pass; i++) {
				if(student[i].id < student[i+1].id) {
					temp = student[i];
					student[i] = student[i+1];
					student[i+1] = temp;
					sorted = 0;
				}
			}
			pass++;
		} while(!sorted);
	}
}

/**************************************************************************************************
Function:	gpaSort
Purpose:	Sorts student[] by student GPA
Inputs:		(1) int num - how many times loop will repeat
			(2) ptr to StudentStruct student[] array - directly modifies
Outputs:	None
Side effects:	StudentStruct student[] array in "main" is directly accessed and modified
**************************************************************************************************/

void gpaSort(StudentStruct student[], int num) {
	int i,
		pass,
		sorted;
	char line[MAX_STUDENT_NAME_LENGTH];
	StudentStruct temp;
	int userinput,
		submenu;	// ascending or descending order

	pass=1;

	do{
		printf("--SUBMENU OPTIONS:--\n");
		printf("1) Ascending order\n");
		printf("2) Descending order\n");
		printf("Choose option: ");

		if (fgets(line, sizeof(line), stdin)) {
			userinput = sscanf(line, "%d", &submenu);
			if ((userinput != 1) && (userinput != 2)) {
				printf("Invalid input, please select one of the two choices.\n");
			}
		}
	} while ((userinput != 1) && (userinput != 2));

	if(submenu == 1) { // sort ascending
		do{
			sorted=1;		// assume arrays are sorted until unordered pair is found

			for(i=0; i < num-pass; i++) {
				if(student[i].gpa > student[i+1].gpa) {
					temp = student[i];
					student[i] = student[i+1];
					student[i+1] = temp;
					sorted = 0;
				}
			}
			pass++;
		} while(!sorted);
	}
	else { // sort descending
		pass=1;
		do{
			sorted=1;		// assume arrays are sorted until unordered pair is found

			for(i=0; i < num-pass; i++) {
				if(student[i].gpa < student[i+1].gpa) {
					temp = student[i];
					student[i] = student[i+1];
					student[i+1] = temp;
					sorted = 0;
				}
			}
			pass++;
		} while(!sorted);
	}
}

/**************************************************************************************************
Function:	exitMenu
Purpose:	Menu option to exit program, calls exit function.
Inputs:		None
Outputs:	None
Side effects:	Exits the program
**************************************************************************************************/

void exitMenu(void) {
	printf("Have a nice day!\n");
	exit(0);
}

/**************************************************************************************************
Function:	printMenu
Purpose:	Prints main menu, displaying 6 choices to the user
Inputs:		None
Outputs:	None
Side effects:	Exits the program
**************************************************************************************************/

void printMenu(void) {
	printf("----------MENU OPTIONS:----------\n");
	printf("1) Sort and print student names alphabetically\n");
	printf("2) Sort and print by student numbers\n");
	printf("3) Sort and print by GPA\n");
	printf("4) Get new student information\n");
	printf("5) Print student information\n");
	printf("6) Exit the program\n");
}

/**************************************************************************************************
Function:	main
Purpose:	Main function of program. Utilizes switch for function calling.
Inputs:		None
Outputs:	return(0) upon exit
Side effects:	None
**************************************************************************************************/

int main(void) {
	StudentStruct students[MAX_STUDENTS];
	int numstudents,
		userinput,
		menu;
	char line[MAX_STUDENT_NAME_LENGTH];

	numstudents = numberOfStudents();
	getStudentData(students, numstudents);

	/* prompt user for main menu choice */
	do {
		do {
			printMenu();
			printf("Enter your menu choice> ");
			if (fgets(line, sizeof(line), stdin)) {
				userinput = sscanf(line, "%d", &menu);
			if ((userinput != 1) || (menu < 1) || (menu > 6)) {
				printf("Invalid input, please select one of the menu choices.\n");
			}
		}
	} while ((userinput != 1) || (menu < 1) || (menu > 6));

	switch(menu){
		case 1:
			alphabetSort(students, numstudents);
			printInfo(students, numstudents);
			break;

		case 2:
			idnumberSort(students, numstudents);
			printInfo(students, numstudents);
			break;

		case 3:
			gpaSort(students, numstudents);
			printInfo(students, numstudents);
			break;

		case 4:
			numstudents = numberOfStudents();
			getStudentData(students, numstudents);
			break;

		case 5:
			printInfo(students, numstudents);
			break;

		case 6:
			exitMenu();
			break;
		}
	} while(1);

return(0);
}

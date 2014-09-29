/*****************************************************************************************
Creator: IHL
Created: 20140715
Last edited: 20140927

Program name: student_sorter.c

Program purpose: 	
This program is designed to prompt user for various pieces of information about a number of students; sort the students alphabetically, by student number, and GPA; and return a sorted list according to which field is selected. I do not utilize Structures on purpose as an exercise.

Functions:
* numStudents = Prompts user for number of students and checks validity (valid responses 1 through 10)
* getData = Prompts user for student information
* printInfo = Prints sorted list of students according to user-defined field
* alphabeticSort = Sorts students names alphabetically
* sortNumber = Sorts students by student number
* sortGPA = Sorts students by GPA
* exitMenu = Exits the program
* printMenu = Prints out the menu options
* main = Main function

*****************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10			// maximum number of students allowed as input
#define LENGTH 31		// maximum size of student name currently accepted

/* gets and checks for number of students */
int numStudents(void) {
	int num, result;
	do {
		printf("Enter the number of students>");
		fflush(stdin);
		result = scanf("%d", &num);
		
		if ((result != 1) || (num <= 0) || (num >= 10)) {
			printf("Invalid input, must be a positive integer from 1 to 10.\n");
		}
	} while ((result != 1) || (num <= 0) || (num >= 10));
	
	return(num);
}

/* gets and checks input from user, called from menu */
void getData(int *pid, double *pgpa, char pname[][LENGTH], int num) {
	int i,
		studnum,
		result;
	
	studnum = 1;
	for (i=0; i<num; i++) {
		printf("Enter name of student #%d>", studnum);
		fflush(stdin);
		scanf("%s", pname[i]);
		
		/* THIS SECTION CANNOT HANDLE ANY STRING CHARACTERS ENTERED AS INPUT PROPERLY. NEED TO UTILIZE FGETS OR SOMETHING ELSE */
		do {
			printf("Enter student number for student #%d>", studnum);
			fflush(stdin);
			
			if(scanf("%d", &pid[i]) != 1 || pid[i] <= 0) {
				printf("Invalid input, ID number must be a positive integer.\n");
				result = 0;
			} else {
				result = 1;
			}
		} while(result != 1);
			/*
			result = scanf("%d", &pid[i]);
			if ((result != 1) || (pid[i] <= 0)) {
				printf("Invalid input, ID number must be a positive integer.\n");
				printf("%d", result);
			}
		} while ((result != 1) || (pid[i] <= 0));
		*/
		
		do {
			printf("Enter the GPA of student #%d>", studnum);
			fflush(stdin);
			
			if(scanf("%lf", &pgpa[i]) != 1 || pgpa[i] < 0.0 || pgpa[i] > 4.0) {
				printf("Invalid input, GPA must be a number between 0.0 and 4.0\n");
				result = 0;
			} else {
				result = 1;
			}
		} while(result != 1);
			/*
			result = scanf("%lf", &pgpa[i]);
			if ((result != 1) || (pgpa[i] < 0.0) ||	(pgpa[i] > 4.0)) {
				printf("Invalid input, GPA must be a number between 0.0 and 4.0\n");
			}
		} while ((result != 1) || (pgpa[i] < 0.0) || (pgpa[i] > 4.0));
		*/
		studnum += 1;
	}
}

/* prints out the information of each student, menu option #5 */
void printInfo(int pid[], double pgpa[], char pname[][LENGTH], int num) {
	int i;
	
	for (i=0; i<num; i++) {
		printf("Student name: %s\n", pname[i]);
		printf("ID number:    %d\n", pid[i]);
		printf("GPA:          %f\n", pgpa[i]);
		printf("\n");
	}
}

/* sort students' names alphabetically, menu option #1 */
void alphabeticSort(char pname[][LENGTH], double pgpa[], int pid[], int num) {
	int i,
		pass,
		sorted,
		result;
	char temp[LENGTH];
	double temp1;
	int temp2;
	
	pass = 1;
	do {
		sorted = 1; // assume arrays are sorted until unordered pair is found. If sorted, skips if statement and exits out.
		
		for (i=0; i < num-pass; i++) {
			result = strcmp(pname[i], pname[i + 1]);
			if (result > 0) {
				strcpy(temp, pname[i]);
				strcpy(pname[i], pname[i + 1]);
				strcpy(pname[i + 1], temp);
				
				temp1 = pgpa[i];
				pgpa[i] = pgpa[i + 1];
				pgpa[i + 1] = temp1;
				
				temp2 = pid[i];
				pid[i] = pid[i + 1];
				pid[i + 1] = temp2;
				
				sorted = 0;
			}
		}
		pass++; // iterate
	} while(!sorted); // while sorted = 0; the loop will continue
}

/* sorts by student number, menu option #2 */
void sortNumber(char pname[][LENGTH], double pgpa[], int pid[], int num) {
	int i,
		pass,
		temp,
		sorted;
	int result,
		submenu;
	double temp1;
	char temp2[LENGTH];
	
	pass = 1;
	
	do {
		// print out SUBMENU OPTIONS //
		printf("--SUBMENU OPTIONS:--\n");
		printf("1) Ascending order\n");
		printf("2) Descending order \n");
		fflush(stdin);
		result = scanf("%d", &submenu);
		if ((result != 1) || (submenu < 1) || (submenu > 2)) {
			printf("Invalid input, please enter one of the menu choices.\n");
		}
	} while ((result != 1) || (submenu < 1) || (submenu > 2));
	
	/* sorts arrays in ascending order */
	if (submenu == 1) {
		do {
			sorted = 1; // assume arrays are sorted until unordered pair is found. If sorted, skips if statement and exits out.
		
			for (i=0; i < num-pass; i++) {
				if (pid[i] > pid[i + 1]) {
				
					// ID numbers in ascending order //
					temp = pid[i];
					pid[i] = pid[i + 1];
					pid[i + 1] = temp;
					sorted = 0;
				
					// GPA in ascending order //
					temp1 = pgpa[i];
					pgpa[i] = pgpa[i + 1];
					pgpa[i + 1] = temp1;
				
					// Names in ascending order //
					strcpy(temp2, pname[i]);
					strcpy(pname[i], pname[i + 1]);
					strcpy(pname[i + 1], temp2);
				}
			}
			pass++; // iterate
		} while(!sorted); // while sorted = 0; the loop will continue
	}

	/* Sorts arrays in descending order, SUBMENU OPTION 2 */
	else {
		pass = 1;
		do {
			sorted = 1; // assume arrays are sorted until unordered pair is found. If sorted, skips if statement and exits out.
		
			for (i=0; i < num-pass; i++) {
				if (pid[i] < pid[i + 1]) {
				
					// ID numbers in descending order //
					temp = pid[i];
					pid[i] = pid[i + 1];
					pid[i + 1] = temp;
					sorted = 0;
				
					// GPA to correspond //
					temp1 = pgpa[i];
					pgpa[i] = pgpa[i + 1];
					pgpa[i + 1] = temp1;
				
					// Names to correspond //
					strcpy(temp2, pname[i]);
					strcpy(pname[i], pname[i + 1]);
					strcpy(pname[i + 1], temp2);
				}
			}
			pass++; // iterate
		} while(!sorted); // while sorted = 0; the loop will continue
	}
}

/* Sorts by GPA, menu option #3 */
void sortGPA(double pgpa[], int pid[], char pname[][LENGTH], int num) {
	int i,
		pass,
		temp1,
		sorted;
	int result,
		submenu;
	double temp;
	char temp2[LENGTH];
	
	pass = 1;
	
	do {
		// print out SUBMENU OPTIONS //
		printf("--SUBMENU OPTIONS:--\n");
		printf("1) Ascending order\n");
		printf("2) Descending order\n");
		fflush(stdin);
		result = scanf("%d", &submenu);
		if ((result != 1) || (submenu < 1) || (submenu > 2)) {
			printf("Invalid input, please enter one of the menu choices.\n");
		}
	} while ((result != 1) || (submenu < 1) || (submenu > 2));
	
	/* sorts arrays in ascending order, SUBMENU OPTION 1 */
	if (submenu == 1) {
		do {
			sorted = 1; // assume arrays are sorted until unordered pair is found. If sorted, skips if statement and exits out.
		
			for (i=0; i < num-pass; i++) {
				if (pgpa[i] > pgpa[i + 1]) {
					
					// GPA in ascending order //
					temp = pgpa[i];
					pgpa[i] = pgpa[i + 1];
					pgpa[i + 1] = temp;
					sorted = 0;
					
					// ID numbers in ascending order //
					temp1 = pid[i];
					pid[i] = pid[i + 1];
					pid[i + 1] = temp1;
				
					// Names in ascending order //
					strcpy(temp2, pname[i]);
					strcpy(pname[i], pname[i + 1]);
					strcpy(pname[i + 1], temp2);
				}
			}
			pass++; // iterate
		} while(!sorted); // while sorted = 0; the loop will continue
	}
	
	/* sorts arrays in descending order, SUBMENU OPTION 2 */
	else {
		pass = 1;
		do {
			sorted = 1; // assume arrays are sorted until unordered pair is found. If sorted, skips if statement and exits out.
		
			for (i=0; i < num-pass; i++) {
				if (pgpa[i] < pgpa[i + 1]) {
					
					// GPA in descending order //
					temp = pgpa[i];
					pgpa[i] = pgpa[i + 1];
					pgpa[i + 1] = temp;
					sorted = 0;
					
					// ID numbers in descending order //
					temp1 = pid[i];
					pid[i] = pid[i + 1];
					pid[i + 1] = temp1;
				
					// Names to correspond //
					strcpy(temp2, pname[i]);
					strcpy(pname[i], pname[i + 1]);
					strcpy(pname[i + 1], temp2);
				}
			}
			pass++; // iterate
		} while(!sorted); // while sorted = 0; the loop will continue
	}
}

/* Exit the program, menu option 6 */
void exitMenu(void) {
	exit(0);
}

/* Prints out the MAIN MENU OPTIONS */
void printMenu(void) {
	printf("----------MENU OPTIONS:----------\n");
	printf("1) Sort and print names alphabetically\n");
	printf("2) Sort and print by student numbers\n");
	printf("3) Sort and print by GPA\n");
	printf("4) Get new student information\n");
	printf("5) Print student information\n");
	printf("6) Exit program\n");
}

int main(void) {
	int		id[MAX];
	double	gpa[MAX];
	char	name[MAX][LENGTH];
	int		num,
			result,
			menu;
			
	num = numStudents();
	getData(id, gpa, name, num);
	
	do {
		do {
			printMenu();
			printf("Enter a menu option>");
			fflush(stdin);
			result = scanf("%d", &menu);
			if ((result != 1) || (menu < 1) || (menu > 6)) {
				printf("Invalid input, please enter one of the menu choices\n");
			}
		} while ((result != 1) || (menu < 1) || (menu > 6));
		
		switch(menu) {
			case 1:
				alphabeticSort(name, gpa, id, num);
				printInfo(id, gpa, name, num);
				break;
				
			case 2:
				sortNumber(name, gpa, id, num);
				printInfo(id, gpa, name, num);
				break;
				
			case 3:
				sortGPA(gpa, id, name, num);
				printInfo(id, gpa, name, num);
				break;
				
			case 4:
				num = numStudents();
				getData(id, gpa, name, num);
				break;
				
			case 5:
				printInfo(id, gpa, name, num);
				break;
				
			case 6:
				exitMenu();
				break;
			}
	} while(1);
return(0);
}
		
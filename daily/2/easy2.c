/* Reddit dailyprogrammer challenge
** easy2.c
** Life expectancy calculator
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const float malelife = 77.4; // USA only
const float femalelife = 82.2; // USA

int main(int argc, char** argv) {

	int ageinyears, gender, userinput;

	int yearleft, monthleft;
	long daysleft, hoursleft, minutesleft, secondsleft;

	char line[2048];


	printf("Hi, this calculator will estimate your life expectancy given your gender and current age. (Based off US life expectancy)\n");

	do {
		printf("Are you male or female?\n");
		printf("1) Male\n");
		printf("2) Female\n");
		printf("Choose option 1 or 2: ");

		if (fgets(line, sizeof(line), stdin)) {
			userinput = sscanf(line, "%d", &gender);
			if ((gender != 1) && (gender != 2)) {
				printf("Just pick 1 or 2 please.\n");
			}
		}
	} while ((userinput == 0) || (userinput == EOF) || ((gender != 1) && (gender != 2)));

	printf("How old are you (in years)?\n");
	printf("> ");
	scanf("%d", &ageinyears);

	printf("Calculating....\n");
	sleep(3);

	if (gender == 1) { // male
		yearleft = malelife - ageinyears;
		monthleft = yearleft * 12;
		daysleft = yearleft * 365 + (yearleft / 4);
		hoursleft = daysleft * 24;
		minutesleft = hoursleft * 60;
		secondsleft = minutesleft * 60;
		printf("Based on estimates by the World Health Organization, and without considering other factors, if you were to live to the average life expectancy for somebody of your gender, this is how much longer you have to live. Have a nice day!\n");

		printf("Years: 		%d\n", yearleft);
		printf("Months: 	%d\n", monthleft);
		printf("Days: 		%lu\n", daysleft);
		printf("Hours: 		%lu\n", hoursleft);
		printf("Minutes: 	%lu\n", minutesleft);
		printf("Seconds: 	%lu\n", secondsleft);
	}
	else { //female
		yearleft = femalelife - ageinyears;
		monthleft = yearleft * 12;
		daysleft = yearleft * 365 + (yearleft / 4);
		hoursleft = daysleft * 24;
		minutesleft = hoursleft * 60;
		secondsleft = minutesleft * 60;
		printf("Based on estimates by the World Health Organization, and without considering other factors, if you were to live to the average life expectancy for somebody of your gender, this is how much longer you have to live. Have a nice day!\n");

		printf("Years: 		%d\n", yearleft);
		printf("Months: 	%d\n", monthleft);
		printf("Days: 		%lu\n", daysleft);
		printf("Hours: 		%lu\n", hoursleft);
		printf("Minutes: 	%lu\n", minutesleft);
		printf("Seconds: 	%lu\n", secondsleft);
	}

	return(0);
}



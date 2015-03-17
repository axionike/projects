/* Project Euler
** 19
** How many Sundays fell on the first of the month during the 21st century -
** 1 Jan 1901 to 31 Dec 2000
** 1 Jan 1900 was a Monday
** Leap years occur on every year divisible by 4
*/

#include <stdio.h>

int main(int argc, char** argv)
{
	int sundays = 0;

	unsigned long day = 2; // monday is 1
	int date = 1; // actual day of the month
	int month = 1; // jan is 1
	int year = 1901;

	for(year = 1901; year < 2001; year++) {
		if(year%4 == 0) { //leap year
			for(month = 1; month < 13; month++) {
				if(month == 9 || month == 4 || month == 6 || month == 11) {
					for(date = 1; date < 31; date++) {
						day++;

						if(date == 1 && (day%7 == 0)) {
							sundays++;
						}
					}
				}else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					for(date = 1; date < 32; date++) {
						day++;

						if(date == 1 && (day%7 == 0)) {
							sundays++;
						}
					}
				} else { // feb
					for(date = 1; date < 30; date++) {
						day++;

						if(date == 1 && (day%7 == 0)) {
							sundays++;
						}
					}
				}
			}
		} else {
			for(month = 1; month < 13; month++) {
				if(month == 9 || month == 4 || month == 6 || month == 11) {
					for(date = 1; date < 31; date++) {
						day++;

						if(date == 1 && (day%7 == 0)) {
							sundays++;
						}
					}
				}else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					for(date = 1; date < 32; date++) {
						day++;

						if(date == 1 && (day%7 == 0)) {
							sundays++;
						}
					}
				} else { // feb
					for(date = 1; date < 29; date++) {
						day++;

						if(date == 1 && (day%7 == 0)) {
							sundays++;
						}
					}
				}
			}
		}
	}

	printf("Number of Sundays = %d\n", sundays);
}

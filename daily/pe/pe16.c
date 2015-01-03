/* Project Euler
** 16
** I have the algorithm correct, but casting ints to char is just not happening.
** Maybe come back to this later at some point.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static long long euler = 0;
static char powerdigit[500];

void initializeArray(void) {
	for (int i=0; i < 500; i++) {
		powerdigit[i] = '\0';
	}
}

unsigned long getSum(void) {

	unsigned long sum = 0;
	int i = 0;

	do {
		sum+=(powerdigit[i] - '0');
		i++;
	} while (powerdigit[i] != '\0' || i < 500);

	printf("i-sum = %d\n", i);

	return sum;
}

void writeDigits(int digits) {

	int j = digits-1;

	do {
		if (2*(powerdigit[j] - '0') >= 10) {
			if (powerdigit[j+1] == '\0') {
				powerdigit[j+1] = (1 - '0');
			}
			else {
				powerdigit[j+1] = ((powerdigit[j+1] - '0') + 1) - '0';
			}
			powerdigit[j] = (((powerdigit[j] - '0') % 5) * 2) - '0';
		}
		else {
			powerdigit[j] = 2*(powerdigit[j] - '0') - '0';
		}
		j--;
	} while (j >= 0);
}


int main(int argc, char** argv) {

	int i;

	initializeArray();

	powerdigit[0] = (1 - '0');
	printf("%.*s\n", 1, powerdigit);

	for (i=0; i < 1000; i++) {
		int digits = 1;

		do {
			digits++;
			//printf("digits = %d\n", digits);
		} while (powerdigit[digits] != '\0');

		writeDigits(digits);
	}

	euler = getSum();

	printf("%llu\n", euler);

return 0;
}


/* Project Euler
** 16
** Sum of the digits of the number 2^1000
** Considerations: This number is definitely too big for a 64-bit unsigned, so will require storing the values in a char array.
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
		if(powerdigit[i] != '\0') {
			sum+=(int)(powerdigit[i] - 48);
			i++;
		}
	} while (powerdigit[i] != '\0' && i < 500);

	printf("i-sum = %lu\n", sum);

	return sum;
}

void writeDigits(int digits) {

	int j = 0;
	int dig1 = 1; //always 1 for tens
	int dig2;

	do {
		if (2*((int)powerdigit[j] - 48) >= 10) {
			dig1 = 1;
			dig2 = ((int)powerdigit[j] - 48) % 10;
			if (powerdigit[j+1] == '\0') {
				powerdigit[j+1] = '1'; // char version of "1"
			}
			else {
				powerdigit[j+1] = (int)(powerdigit[j+1] - 48) + 1;
			}
			powerdigit[j] = ( (int)(powerdigit[j] - 48) * 2) + 48;
		}
		else {
			powerdigit[j] = 2*((int)(powerdigit[j] - 48)) + 48;
		}
		j++;
	} while (powerdigit[j] != '\0');

}


int main(int argc, char** argv) {

	int i;

	initializeArray();

	powerdigit[0] = 49;
	// printf("%.*s\n", 1, powerdigit);

	for (i=0; i <= 1000; i++) {
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


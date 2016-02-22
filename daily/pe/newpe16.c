/* Project Euler
** 16
** Sum of the digits of the number 2^1000
** Considerations: This number is definitely too big for a 64-bit unsigned, so the solution I've implemented stores the digits in a char array. This is most definitely not the simplest nor most elegant solution, but it works without requiring any external libraries (other than stdio), e.g. GMP bigint, etc...
*/

#include <stdio.h>

static long long euler = 0;
static char powerdigit[501];

// initialize char array with nul terminator \0, could use any char other than '0' through '9'
void initializeArray(void) {
	for (int i=0; i < 501; i++) {
		powerdigit[i] = '\0';
	}
}

// doubles each digit in array and carries remainder from left to right
void calculate(void) {

	int i = 0;
	int j = 0;
	int dig2 = 0;
	int counter = 0;
	int location = 0; // location of first digit

	// get number of digits so far
	for(i=500; i > 0; i--) {
		if(powerdigit[i] != '\0') {
			counter++;
		} else {
			break;
		}
	}

	location = 501-counter; // array location of "first" digit
	j = location;

	do {
		if (2*(powerdigit[j] - '0') >= 10) {
			dig2 = (2*(powerdigit[j] - '0') % 10);
			//printf("remainder = %d\n", dig2);
			location--;

			if (powerdigit[j-1] == '\0') {
				powerdigit[j-1] = '1'; // char version of "1"
			}
			else {
				powerdigit[j-1] = ((powerdigit[j-1] - '0') + 1) + 48;
			}
			powerdigit[j] = dig2 + 48;
		}
		else {
			powerdigit[j] = 2*(int)(powerdigit[j] - '0') + 48;
		}
		j++;
	} while (powerdigit[j] != '\0' && j < 501);

	// return location;
}

void printnumber(void) {
	int location = 0;
	int num = 0;
	int j = 0;

	while(powerdigit[j] == '\0') {
		location++;
		j++;
	}

	for(int i = location; i < 501; i++) {
		num = powerdigit[i] - '0';
		printf("%d", num);
	}

	printf("\n");
}


unsigned long getSum(void) {
	int i = 0;
	int counter = 0;
	int location = 0; // location of first digit
	unsigned long sum = 0;

	// get number of digits in number
	for(i=500; i > 0; i--) {
		if(powerdigit[i] != '\0') {
			counter++;
		} else {
			break;
		}
	}

	location = 501-counter;

	for(i = location; i < 501; i++) {
		sum+= (powerdigit[i] - '0');
	}

	return sum;
}


int main(int argc, char** argv)
{

	unsigned long euler = 0;
	int i = 0;

	powerdigit[500] = '1'; // 2 ^ 0 to start

	for(i = 1; i <= 1000; i++) {
		calculate();
		printf("2^%d = ", i);
		printnumber();
	}

	printf("2^1000 = %s\n", powerdigit);
	euler = getSum();

	printf("%lu\n", euler);

	return 0;
}

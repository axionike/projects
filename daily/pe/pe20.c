/* Project Euler
** 20
** Sum of digits of 100! (100 factorial)
** Again, this number will be at least 100 digits long, too big for 64-bit variable
** My implementation stores the result in a char array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long euler = 0;
char powerdigit[502];
char tempdigit[502]; // temp

void initializeArray(void) {
	for (int i=0; i < 502; i++) {
		powerdigit[i] = '\0';
	}

	for (int i=0; i < 502; i++) {
		tempdigit[i] = '\0';
	}

}

void printnumber(void) {
	int location = 0;
	int num = 0;
	int j = 0;

	while(powerdigit[j] == '\0') {
		location++;
		j++;
	}

	printf("digit location = %d\n", location);

	for(int i = location; i < 502; i++) {
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
	for(i=501; i > 0; i--) {
		if(powerdigit[i] != '\0') {
			counter++;
		} else {
			break;
		}
	}

	location = 501-counter;

	// possible logical error here
	for(i = location; i < 502; i++) {
		sum+= (powerdigit[i] - '0');
	}

	return sum;
}

void multiply(int factor)
{
	// get current number in char array
	// "add" that number to itself x times (factor)

	int j = 0;
	int dig2 = 0;
	int multiple = factor-1;

	j = 500;

	while(multiple > 0 && j > 0) {
		if(tempdigit[j] == '\0') {
			break;
		}

		if((int)(tempdigit[j] - '0') + (int)(powerdigit[j] - '0') >= 10) {
			dig2 = ((int)((tempdigit[j] - '0') + (powerdigit[j] - '0')) % 10);

			if (powerdigit[j-1] == '\0') {
				powerdigit[j-1] = '1'; // char version of "1"
			}
			else {
				powerdigit[j-1] = (int)((powerdigit[j-1] - '0') + 1) + '0';
			}
			powerdigit[j] = dig2 + '0';
		}
		else {
			powerdigit[j] = (int)(tempdigit[j] - '0') + (int)(powerdigit[j] - '0') + '0';
		}
		j--;
		multiple--;
	}
	/*
	size_t destination_size = sizeof (tempdigit);
	strncpy(powerdigit, tempdigit, destination_size);
	powerdigit[destination_size - 1] = '\0';
	*/
}

int main(int argc, char** argv)
{

	unsigned long euler = 0;
	int i = 0;

	initializeArray();

	powerdigit[500] = '1'; // 2 ^ 0 to start
	tempdigit[500] = '1';

	for(i = 2; i <= 100; i++) {
		multiply(i);
		printf("%d! = ", i);
		printnumber();
	}

	euler = getSum();

	printf("%lu\n", euler);

	return 0;
}

/* Project Euler
** 14
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

static long long euler = 0;
static long collatz = 3000001;
static int chains[3000001];

void initializeChains(void) {
	for (int i=0; i < collatz; i++) {
		chains[i] = 0;
	}
}

/* recursion doesn't seem to work for numbers this large unless increase stack size
** which I kinda don't want to do on this machine. So, going to implement iteration only
** instead.

long chainLength(long number_to_check) {
	printf("+1 ");
	if (chains[number_to_check]) {
		return chains[number_to_check];
	}

	if (number_to_check == 1) {
		chains[number_to_check] = 1;
	}
	else if (number_to_check % 2 == 0) {
		chains[number_to_check] = 1 + chainLength(number_to_check / 2);
	}
	else {
		chains[number_to_check] = 1 + chainLength(3*number_to_check + 1);
	}
	return chains[number_to_check];

	/*
	if (chains[number_to_check] == 0) { //empty
		temp = number_to_check;
		if (temp % 2 == 0) {
			temp/=2;
			chains[number_to_check] = chainLength(temp)+1;
		}
		else {
			temp = 3 * temp + 1;
			chains[number_to_check] = chainLength(temp)+1;
		}
		return chains[number_to_check];
	}
}
*/

unsigned long long chainLength(unsigned long long i) {
	if (i % 2 == 0) {
		return (i/2);
	}
	else {
		return (3*i + 1);
	}
}

int main(int argc, char** argv) {

	unsigned long long i, temp, step;
	unsigned long largest = 1;

	initializeChains();
	chains[0] = chains[1] = 1;

	temp = largest;

	for (i=2; i < collatz; i++) {
		step = 0;
		temp = i;

		do {
			temp = chainLength(temp);
			step++;
		} while (temp > i - 1);

		chains[i] = step + chains[temp];

		if (chains[i] > largest) {
			largest = chains[i];
			printf("%llu %lu\n", i, largest);
		}

	}

	euler = largest;

	printf("%llu\n", euler);

return 0;
}


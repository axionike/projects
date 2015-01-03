/* Project Euler
** 492
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

static long long euler = 0;
static long long b_x = 1000000000;
static long long b_y = 1000;
static long long b_n = 1000;
static unsigned long int firstprime = 1000000007;



int isPrime (long long number) {

	unsigned long long j = 2;
	for (j=2; j*j<=number; j++) {
		if (number % j == 0) return 0;
	}
	return 1;
}


/* Input is first prime between b_x and b_x+b_y. Returns a_n mod p for that single prime.
** Rest of modulos for remaining primes is calculated by adding difference between
** remaining primes.

void printFirstTerms(unsigned long number) {
	long long countup;
	unsigned long long counter;
	int modulo;

	for (countup=1; countup < number; countup++) {
		if (countup == 1) {
			counter = 1;
		} else {
			counter = ((6 * counter * counter) + (10 * counter) + 3);
		}
		modulo = counter % 7;
		printf("%lld %llu %d\n", countup, counter, modulo);
	}
}
*/


/* General idea: find a_n mod p for first prime in sequence. Iterate sumprimes based off
** that result (add the difference between following primes in sequence to sumprimes).
*/

int main(int argc, char** argv) {

	unsigned long long primecheck;
	unsigned long int sumprimes = 0;
	unsigned long int modulo = 1;

	int primecounter = 0;
	unsigned long long i;

	for (i=b_x; i < b_x+b_y; i++) {
		if (isPrime(i)) {
			primecounter++;
		}
	}

	printf("%d\n", primecounter);

return 0;
}

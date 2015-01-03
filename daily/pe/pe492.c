/* Project Euler
** 492
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

static long long euler = 0;
static long long b_x = 1000000000;
static long long b_y = 10000000;
static long long b_n = 1000000000000000;



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
*/

unsigned long long calMod(unsigned long long n, unsigned long int prime) {
	unsigned long long i;
	unsigned long long modulo = 1;

	for (i=1; i < n; i++) {
		modulo = modulo % prime;
		modulo = (((((6 * modulo) % prime) * modulo) % prime) + ((10 * modulo) % prime) + 3) % prime;
	}

	return modulo;

}


/* Once a modulo repeats itself twice, the remaining modulos for every sequence thereafter
** will be the same, by definition of the sequence. Just need to find that first repeated
** term...

unsigned long int findMod(unsigned long int counter) {
	unsigned long long countup;
	unsigned long int modulo[counter+1];

	for (countup=1; countup < counter; countup++) {
		if (prevmodulo == modulo) {
			printf("%llu %ld\n", countup, modulo);
			break;
		} else {
			prevmodulo = modulo;
			modulo = ((6 * modulo * modulo) + (10 * modulo) + 3) % firstprime;
		}
	}

	printf("%llu %ld\n", countup, modulo);
	return modulo;
}
*/

/* General idea: find a_n mod p for first prime in sequence. Iterate sumprimes based off
** that result (add the difference between following primes in sequence to sumprimes).
*/
int main(int argc, char** argv) {

	unsigned long long primecheck;
	unsigned long long sumprimes = 0;
	unsigned long int i;

	for (i=b_x; i <= b_x+b_y; i++) {
		if (isPrime(i)) {
			printf("%ld\n", i);
			sumprimes+=calMod(b_n, i);
		}
	}

	printf("%llu\n", sumprimes);

return 0;
}

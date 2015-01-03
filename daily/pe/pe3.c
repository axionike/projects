/* Project Euler
** 3
*/

#include <stdio.h>
#include <stdlib.h>

static long largest_factor = 2;
static unsigned long long danumba = 600851475143;

int isPrime (long long number) {
	if (number <= 1) return 0;
	unsigned long long i;
	for (i=2; i*i<=number; i++) {
		if (number % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char** argv) {
	unsigned long long current = 2;

	for (current=2; current*current <= danumba; current++) {
		if (danumba % current == 0 && isPrime(current)) {
			largest_factor = current;
		}
	}

	printf("The largest prime factor of the number is: %lu\n", largest_factor);

return 0;
}


/* Project Euler
** 7
*/

#include <stdio.h>
#include <math.h>

static int euler = 0;
static int prime_counter = 10001;

int isPrime (int number) {

	unsigned int j = 2;
	for (j=2; j*j<=number; j++) {
		if (number % j == 0) return 0;
	}
	return 1;
}

int main(int argc, char** argv) {
	int prime = 5;
	int i = 2;

	while (i < prime_counter) {
		if (isPrime(prime) && i < prime_counter) {
			i++;
			printf("%d %d\n", i, prime);

			prime++;
		}
		else {
			prime++;
		}
	}

	euler = prime-1;

	printf("%d\n", euler);

return 0;
}


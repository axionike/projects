/* Project Euler
** 5
*/

/* Start with 1. Divide by 1-20 each. If any of 1-20 results in a remainder,
** increase++, and restart the counter. Whatever that value is
** the smallest positive number that can be evenly divided by all 1-20.
*/

#include <stdio.h>

static int euler = 0;

int divides(int number) {
	int divisor = 20;
	int i = 2;

	while (i < divisor && number % i == 0) {
		i++;
	}

	if (i == divisor && i % divisor == 0) return 0;
	else return 1;
}

int main(int argc, char** argv) {
	int current = 2;

	while (divides(current)) {
		current++;
	}

	euler = current;

	printf("%d\n", euler);

return 0;
}


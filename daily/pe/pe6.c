/* Project Euler
** 6
*/

#include <stdio.h>
#include <math.h>

static int euler = 0;

int main(int argc, char** argv) {
	long sum_squares = 0;
	long square_sums = 0;
	int i = 0;

	for (i=0; i<=100; i++ ) {
		sum_squares+=i*i;
	}

	for (i=0; i<=100; i++) {
		square_sums+=i;
	}
	square_sums*=square_sums;

	euler = square_sums - sum_squares;

	printf("%d\n", euler);

return 0;
}


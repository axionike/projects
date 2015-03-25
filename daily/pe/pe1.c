/* Project Euler 
** 1
*/

#include <stdio.h>
#include <stdlib.h>

static int sum_of_multiples = 0;

int main(int argc, char** argv) {
	int i;
	
	for (i = 0; i < 1000; i++) {
		if (((i % 3) == 0) || ((i % 5) == 0)) {
			sum_of_multiples = sum_of_multiples + i;
		}
	}

	printf("The sum of all multiples of 3 and 5 below 1000 is: %d\n", sum_of_multiples);

	return 0;
}


/* Project Euler 
** 2
*/

#include <stdio.h>
#include <stdlib.h>

static int sum_of_evens = 2;

int main(int argc, char** argv) {
	int first=1;
	int second=2;
	int current=3;
	
	while (current < 4000000) {
		first = second;
		second = current;
		current = first + second;
		if ((current % 2) == 0) {
			sum_of_evens+=current;
		}
	}

	printf("The sum of all even Fibonacci terms under 4,000,000 is: %d\n", sum_of_evens);

return 0;
}


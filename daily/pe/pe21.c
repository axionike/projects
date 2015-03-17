/* Project Euler
** 21
** Amicable numbers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long euler = 0;

unsigned long sumDivisors(int number) {

	int i = 1;
	unsigned long sum = 0;

	for(i = 1; i <= number/2; i++) {
		if(number % i == 0) {
			sum+=i;
		}
	}
	return sum;
}

int main(int argc, char** argv)
{

	int i; // counter
	unsigned long sum;
	unsigned long amicable;

	for(i = 1; i < 10000; i++) {
		sum = sumDivisors(i);
		amicable = sumDivisors(sum);

		if(amicable == i && amicable < 10000 && i != sum) {
			euler+=(i + sum);
			printf("Sum = %lu | i = %d\n", sum, i);
			printf("Euler = %llu\n", euler);
		}
	}

	euler/=2; // negate duplicates

	printf("%llu\n", euler);
}

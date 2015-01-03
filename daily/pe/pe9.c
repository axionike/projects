/* Project Euler
** 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

static long long euler = 0;
static int pythagorean = 1000;

int main(int argc, char** argv) {

	int a,b,c;
	int i,j,k;

	for (i=1; i < 500; i++) {
		for (j=i+1; j < 500; j++) {
			for (k=j+1; k < 500; k++) {
				if ((i*i + j*j == k*k) && (i+j+k == pythagorean)) {
					a = i;
					b = j;
					c = k;
				}
			}
		}
	}

	printf("%d %d %d\n", a, b, c);

	euler = a*b*c;

	printf("%llu\n", euler);

return 0;
}


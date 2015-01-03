/* Project Euler
** 15
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

static long long euler = 0;;
static long thegrid[21][21]; // even though there are 20 "boxes" in the grid, there are actually 21 vertices to account for
static const int dimension = 20;


int main(int argc, char** argv) {

	int i, j;

	for (i=0; i < dimension+1; i++) {
		for (j=0; j < dimension+1; j++) {
			if (i == 0 || j == 0) {
				thegrid[i][j] = 1;
			}
			else {
				thegrid[i][j] = thegrid[i-1][j] + thegrid[i][j-1];
				printf("%ld\n", thegrid[i][j]);
			}
		}
	}


	euler = thegrid[dimension][dimension];

	printf("%llu\n", euler);

return 0;
}


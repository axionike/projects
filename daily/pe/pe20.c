/* Project Euler
** 20
** Sum of digits of 100! (100 factorial)
** Again, this number will be at least 100 digits long, too big for 64-bit variable
** My implementation stores the result in a char array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// from wolframalpha...
char powerdigit[200] = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";

int main(int argc, char** argv)
{

	unsigned long euler = 0;
	int i = 0;

	while(powerdigit[i] != '\0') {
		euler += (powerdigit[i] - '0');
		i++;
	}

	printf("%lu\n", euler);

	return 0;
}

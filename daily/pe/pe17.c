/* Project Euler
** 17
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

static long long euler = 0;

int main(int argc, char** argv) {

	int hundred = 7;
	int and = 3;
	int one = 3;
	int two = 3;
	int three = 5;
	int four = 4;
	int five = 4;
	int six = 3;
	int seven = 5;
	int eight = 5;
	int nine = 4;
	int ten = 3;
	int eleven = 6;
	int twelve = 6;
	int thirteen = 8;
	int fourteen = 8;
	int fifteen = 7;
	int sixteen = 7;
	int seventeen = 9;
	int eighteen = 8;
	int nineteen = 8;
	int twenty = 6;
	int thirty = 6;
	int forty = 5;
	int fifty = 5;
	int sixty = 5;
	int seventy = 7;
	int eighty = 6;
	int ninety = 6;

	euler = (10* (9*(one+two+three+four+five+six+seven+eight+nine) + ten)) +
	(10*(eleven+twelve+thirteen+fourteen+fifteen+sixteen+seventeen+eighteen+nineteen)) +
	(10*10*(twenty+thirty+forty+fifty+sixty+seventy+eighty+ninety)) +
	(100*9*hundred) + (99*9*and) + 100*(one+two+three+four+five+six+seven+eight+nine) + 11;

	printf("%llu\n", euler);

return 0;
}


/* Reddit dailyprogrammer challenge
** easy1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char name[2048];
static char age[2048];
static char username[2048];

void trim (char *s) {
	int i = strlen(s)-1;
	if ((i > 0) && (s[i] == '\n'))
		s[i] = '\0';
}

int main(int argc, char** argv) {
	int i = 0;

	puts("Well, I'm going to ask you a few questions.\n");
	fputs("What is your name? ", stdout);
	fgets(name, 2048, stdin);
	fputs("How old are you? ", stdout);
	if (fgets(age, 2048, stdin) != NULL) {
		i = atoi(age);
	}
	fputs("Please enter your user name: ", stdout);
	fgets(username, 2048, stdin);

	trim(name);
	trim(username);

	printf("Hi %s, you're %d years old, and your username is %s.\n", name, i, username);

	return 0;
}



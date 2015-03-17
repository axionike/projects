/* Project Euler
** 22
** Numbers of Names
*/

#include <stdio.h>
#include <string.h>
#define MAX_NAME 20
#define NUM_NAMES 5163

unsigned long long euler;
char names[NUM_NAMES][MAX_NAME];
char finalnames[NUM_NAMES][MAX_NAME];

void alphabetSort(const char a[][MAX_NAME], char b[][MAX_NAME])
{
    char temp[MAX_NAME];
    int i,j,cmp;
    unsigned long long iterations = 0;

    // copy a to b
    for (i = 0; i < NUM_NAMES; i++){
        strcpy(b[i], a[i]);
    }

    // in-place sort the b array
    for(i = 0; i < NUM_NAMES; i++){
        for(j = 0; j < NUM_NAMES-1; j++){

        	cmp = strcmp(b[j], b[j+1]);

            if(cmp > 0){
                strcpy(temp, b[j+1]);
                strcpy(b[j+1], b[j]);
                strcpy(b[j], temp);
            }
            // iterations++;
            // printf("iterations = %llu\n", iterations); // bubble sort is bad...
        }
    }
}

void addNames(void)
{
	// go through each string
	// add char ascii values together
	// multiple by position in list 1- 5163

	int i, j;
	int namescore = 0;

	for(i = 0; i < NUM_NAMES; i++) {
		namescore = 0;
		for(j = 0; j < MAX_NAME; j++) {
			if(finalnames[i][j] == '\n') { break; }
			else {
				namescore += finalnames[i][j]-64;
				printf("namescore for name %d = %d\n", i+1, namescore);
			}
		}
		printf("Final namescore for name %d = %d\n", i+1, (namescore * (i+1)));
		euler += (namescore * (i+1));
		printf("euler = %llu\n", euler);
	}
}

int main (int argc, char** argv)
{
	int i = 0; // name counter

	FILE *fin = fopen ("p022_names.txt", "r");

	// read in names and store in names array, currently stores \n character
	if (fin != NULL) {
		while( (fgets(names[i],MAX_NAME,fin) != NULL) && (i < NUM_NAMES) ) {
			printf("%s\n",names[i++]);
		}
	fclose (fin);
	}

	alphabetSort(names, finalnames);
	addNames();

	printf("final euler = %llu\n", euler);

}

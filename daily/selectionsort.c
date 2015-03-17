#include <stdio.h>

int main(int argc, char *argv[])
{
	int START = 0;
	int END = 10;
	int d[10] = {5,4,3,2,1,0,9,8,7,6};

	int wheremin = 0;

	int i,j, min;

	for(i=0; i < END; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");

	for(i=START; i<END; i++)
	{
		min=d[i];
		for(j=i;j<END;j++)
		{
			if(min >=d[j])
			{
				min=d[j];
				wheremin=j;
			}
		}

		// d[wheremin]=d[i];
		// d[i]=min;
	}

	printf("Should be sorted now.\n");
	for(i=0; i < END; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");
}

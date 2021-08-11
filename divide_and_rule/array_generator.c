#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("input file name!\n");
		return 0;
	}
	FILE *output = fopen(argv[1], "w");
	int n = 0;
	scanf("%d", &n);

	srand(time(NULL));

	fprintf(output, "%d\n", n);
	for(int i = 0; i < n; i++)
	{
		fprintf(output, "%d ", rand() % 10);
	}
	printf("\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0, max = 0;

	scanf("%d", &n);

	int *arr = (int *)calloc(n, sizeof(int));
	int *subsolution = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);

		for(int j = 0; j < i; j++)
		{
			if(arr[i] % arr[j] == 0 && subsolution[i] < subsolution[j] + 1)
			{
				subsolution[i] = subsolution[j] + 1;
			}
		}
		if(subsolution[i] == 0)
		{
			subsolution[i] = 1;
		}
		if(max < subsolution[i])
		{
			max = subsolution[i];
		}
	}

	printf("%d\n", max);

	free(arr);
	free(subsolution);
	
	return 0;
}
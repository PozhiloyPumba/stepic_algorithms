#include <stdio.h>
#include <stdlib.h>

//=====================================================================================================

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	if(n == 1)
	{
		int answer = 0;
		scanf("%d", &answer);
		printf("%d", answer);
		return 0;
	}

	int *stair = (int *)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", stair + i);
	}

	int *arr = (int *)malloc(n * sizeof(int));
	
	arr[0] = stair[0];
	arr[1] = (stair[0] + stair[1] > stair[1]) ? stair[0] + stair[1] : stair[1];

	for(int i = 2; i < n; i++)
	{
		arr[i] = -1000000;
	}

	for(int i = 0; i < n - 1; i++)
	{
		if(arr[i + 1] < arr[i] + stair[i + 1])
		{
			arr[i + 1] = arr[i] + stair[i + 1];
		}
		if(i + 2 < n && arr[i + 2] < arr[i] + stair[i + 2])
		{
			arr[i + 2] = arr[i] + stair[i + 2];
		}
	}
	
	printf("%d\n", arr[n - 1]);

	free(arr);
	free(stair);

	return 0;
}
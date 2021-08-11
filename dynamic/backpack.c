#include <stdio.h>
#include <stdlib.h>

//=====================================================================================================

int backpack(int *ingots, int W, int n);

//=====================================================================================================

int main()
{
	int W = 0, n = 0;

	scanf("%d%d", &W, &n);

	int *ingots = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", ingots + i);
	}

	printf("%d\n", backpack(ingots, W, n));

	free(ingots);

	return 0;
}

//=====================================================================================================

int backpack(int *ingots, int W, int n)
{
	int *arr = (int *)calloc((W + 1) * (n + 1), sizeof(int));
	int max = 0;
	arr[0] = 1;

	for(int i = 0; i <= n; i++)
	{
		arr[(W + 1) * i] = 1;
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= W; j++)
		{
			if(arr[(i - 1) * (W + 1) + j] == 1)
			{
				arr[i * (W + 1) + j] = 1;
			}
			
			if(ingots[i - 1] <= j)
			{
				if(arr[(j - ingots[i - 1]) + (W + 1) * (i - 1)] == 1)
				{
					arr[i * (W + 1) + j] = 1;
					if(j > max)
					{
						max = j;
					}
				}	
			}
		}
	}

	free(arr);

	return max;
}

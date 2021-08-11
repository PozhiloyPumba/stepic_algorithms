#include <stdio.h>
#include <stdlib.h>

//=====================================================================================================

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int *)malloc(2 * (n + 1) * sizeof(int));
	
	arr[n] = 0;
	for(int i = 1; i < n; i++)
	{
		arr[i] = 1000000;
	}

	for(int i = n; i > 1; i--)
	{
		if(i % 3 == 0)
		{
			if(arr[i / 3] > arr[i] + 1)
			{
				arr[i / 3] = arr[i] + 1;
				arr[n + 1 + i / 3] = 2;
			}
		}
		if(i % 2 == 0)
		{
			if(arr[i / 2] > arr[i] + 1)
			{
				arr[i / 2] = arr[i] + 1;
				arr[n + 1 + i / 2] = 1;
			}
		}
		if(arr[i - 1] > arr[i] + 1)
		{
			arr[i - 1] = arr[i] + 1;
			arr[n + i] = 3;
		}
	}
	
	printf("%d\n", arr[1]);

	int number = 1;
	while(number != n)
	{
		printf("%d ", number);
		if(arr[n + 1 + number] == 1)
		{
			number *= 2;
			continue;
		}
		if(arr[n + 1 + number] == 2)
		{
			number *= 3;
			continue;
		}
		if(arr[n + 1 + number] == 3)
		{
			number++;
			continue;
		}
	}
	printf("%d\n", number);

	free(arr);

	return 0;
}
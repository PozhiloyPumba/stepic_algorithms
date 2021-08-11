#include <stdio.h>
#include <stdlib.h>

//=====================================================================================================

int binary_search_increase(int *arr, int size, int key);

//=====================================================================================================

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *arr = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}

	int count = 0;
	scanf("%d", &count);
	int *answer = (int *)calloc(count, sizeof(int));

	for(int i = 0; i < count; i++)
	{
		int value = 0;
		scanf("%d", &value);

		answer[i] = binary_search_increase(arr, n, value);
	}

	for(int i = 0; i < count; i++)
	{
		printf("%d ", answer[i]);
	}

	free(arr);
	free(answer);

	return 0;
}

//=====================================================================================================

int binary_search_increase(int *arr, int size, int key)
{
	int l = 0, r = size - 1, mid = (size - 1) / 2;

	while(l <= r)
	{
		if(arr[mid] == key)
		{
			return mid + 1;
		}
		else
		{
			if(arr[mid] < key)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		mid = (l + r) / 2;
	}

	return -1;
}
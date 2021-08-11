#include <stdio.h>
#include <stdlib.h>

//=====================================================================================================

const int MAX = 1000000001;

//=====================================================================================================

int binary_search_decrease(int *arr, int size, int key);

//=====================================================================================================

int main()
{
	int n = 0, max_length = 0;

	scanf("%d", &n);

	int *arr = (int *)calloc(n, sizeof(int));
	int *prev = (int *)calloc(n, sizeof(int));
	int *pos = (int *)calloc(n, sizeof(int));
	int *d = (int *)calloc(n + 1, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		d[i] = -MAX;
	}
	d[0] = MAX;
	d[n] = -MAX;
	pos[0] = -1;

	for(int i = 0; i < n; i++)
	{
		int j = binary_search_decrease(d, n + 1, arr[i]);

		if(d[j - 1] >= arr[i] && arr[i] >= d[j])
		{
			d[j] = arr[i];
			pos[j] = i;
			max_length = (max_length > j) ? max_length : j;
			prev[i] = pos[j - 1];
		}
	}

	printf("%d\n", max_length);

	int *answer = (int *)calloc(max_length, sizeof(int));

	int position = pos[max_length];


	for(int i = max_length - 1; i >= 0 && position != -1; i--)
	{
		answer[i] = position + 1;
		position = prev[position];
	}

	for(int i = 0; i < max_length; i++)
	{
		printf("%d ", answer[i]);
	}
	printf("\n");

	free(arr);
	free(pos);
	free(d);
	free(prev);
	free(answer);

	return 0;
}

//=====================================================================================================

int binary_search_decrease(int *arr, int size, int key)
{
	int l = 0, r = size - 1, mid = (size - 1) / 2;

	while(l <= r)
	{
		if(arr[mid] >= key)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
		mid = (l + r) / 2;
	}

	return mid + 1;
}
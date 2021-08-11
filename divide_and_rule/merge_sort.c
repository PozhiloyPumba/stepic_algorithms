#include <stdio.h>
#include <stdlib.h>

//=====================================================================================================

unsigned long long counter = 0;

//=====================================================================================================

int *merge_sort(int *up, int *down, int left, int right);

void merge(int *arr1, int *arr2);

//=====================================================================================================

int main()
{
	int n = 0;
	scanf("%d", &n);

	int *up = (int *)calloc(n, sizeof(int));
	int *down = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", up + i);
	}

	merge_sort(up, down, 0, n - 1);

	printf("%llu\n", counter);

	free(up);
	free(down);

	return 0;
}

//=====================================================================================================

int *merge_sort(int *up, int *down, int left, int right)
{
	if(left == right)
	{
		down[left] = up[left];
		return down; 
	}

	int mid = (left + right) / 2;
	int cur_left = left;
	int cur_right = mid + 1;
	int *left_arr = merge_sort(up, down, left, mid);
	int *right_arr = merge_sort(up, down, mid + 1, right);
	int *total = (left_arr == up) ? down : up;

	for(int i = left; i <= right; i++)
	{
		if(cur_left <= mid && cur_right <= right)
		{
			if(left_arr[cur_left] <= right_arr[cur_right] )
			{
				total[i] = left_arr[cur_left];
				cur_left++;
			}
			else
			{
				total[i] = right_arr[cur_right];
				cur_right++;
				counter += mid - cur_left + 1;
			}
		}
		else
		{
			if(cur_left > mid)
			{
				total[i] = right_arr[cur_right];
				cur_right++;
			}
			else
			{
				total[i] = left_arr[cur_left];
				cur_left++;
			}
		}
	}

	return total;
}

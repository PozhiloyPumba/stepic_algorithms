#include <stdio.h>
#include <stdlib.h>

#define REPEATS

//=====================================================================================================

struct borders{
	int left, right;
};

struct line{
	int left, right;
};

struct point{
	int coordinate, count;
};

//=====================================================================================================

void quicksort(int *arr, int left, int right);

int partition_2(int *arr, int left, int right);

struct borders partition_3(int *arr, int left, int right);

int count_median(int *arr, int left, int right);

void swap(int *a, int *b);

int binary_search_increase_left(int *arr, int size, int key);

int binary_search_increase_right(int *arr, int size, int key);

//=====================================================================================================

int main()
{
	int count_lines = 0, count_dots = 0;
	scanf("%d%d", &count_lines, &count_dots);

	int *arr_lines_left = (int *)calloc(count_lines, sizeof(int));
	int *arr_lines_right = (int *)calloc(count_lines, sizeof(int));
	struct point *arr_dots = (struct point *)calloc(count_dots, sizeof(struct point));

	for(int i = 0; i < count_lines; i++)
	{
		scanf("%d%d", arr_lines_left + i, arr_lines_right + i);
	}

	quicksort(arr_lines_left, 0, count_lines - 1);
	quicksort(arr_lines_right, 0, count_lines - 1);

	for(int i = 0; i < count_dots; i++)
	{
		scanf("%d", &arr_dots[i].coordinate);

		int index_left = binary_search_increase_left(arr_lines_left, count_lines, arr_dots[i].coordinate);
		int index_right = binary_search_increase_right(arr_lines_right, count_lines, arr_dots[i].coordinate);
		// printf("left = %d right = %d\n", index_left, index_right);
		arr_dots[i].count = abs(index_left - index_right);		
	}

	// for(int i = 0; i < count_lines; i++)
	// {
	// 	printf("%d %d\n", arr_lines_left[i], arr_lines_right[i]);
	// }

	for(int i = 0; i < count_dots; i++)
	{
		printf("%d ", arr_dots[i].count);
	}
	printf("\n");

	return 0;
}

//=====================================================================================================

void quicksort(int *arr, int left, int right)
{
	if(left >= right)
	{
		return;
	}

	#ifdef REPEATS
		struct borders pivot = partition_3(arr, left, right);

		quicksort(arr, left, pivot.left - 1);
		quicksort(arr, pivot.right + 1, right);

	#else
		int pivot = partition_2(arr, left, right);

		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	
	#endif
}

//-----------------------------------------------------------------------------------------------------

int partition_2(int *arr, int left, int right)
{	
	int median = count_median(arr, left, right);
	int border = left + 1;

	if(median != left)
	{
		swap(arr + left, arr + median);
	}

	for(int i = left + 1; i <= right; i++)
	{
		if(arr[i] < arr[left])
		{
			swap(arr + border, arr + i);
			border++;
		}
	}
	swap(arr + border - 1, arr + left);
	
	return border - 1;
}

//-----------------------------------------------------------------------------------------------------

struct borders partition_3(int *arr, int left, int right)
{
	int median = arr[count_median(arr, left, right)];

	int border_left = left;
	int border_right = right;
	int mid = left;

	while(mid <= border_right)
	{
		if(arr[mid] > median)
		{
			swap(arr + mid, arr + border_right);
			border_right--;
		}
		else if(arr[mid] < median)
		{
			swap(arr + mid, arr + border_left);
			border_left++;
			mid++;
		}
		else
		{
			mid++;
		}
	}

	struct borders pivot = {border_left, mid - 1};
	return pivot;
}

//-----------------------------------------------------------------------------------------------------

int count_median(int *arr, int left, int right)
{
	int mid = (left + right) / 2;

	if(arr[left] <= arr[right])
	{
		if(arr[mid] <= arr[left])
		{
			return left;
		}
		else if (arr[mid] >= arr[right])
		{
			return right;
		}
		return mid;
	}
	else	// arr[left] > arr[right]
	{
		if(arr[mid] >= arr[left])
		{
			return left;
		}
		else if (arr[mid] < arr[right])
		{
			return right;
		}
	}
	return mid;
}

//-----------------------------------------------------------------------------------------------------

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//-----------------------------------------------------------------------------------------------------

int binary_search_increase_right(int *arr, int size, int key)
{
	int l = 0, r = size - 1, mid = (size - 1) / 2;

	while(l <= r)
	{
		if(arr[mid] < key)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
		mid = (l + r) / 2;
	}
	if(mid == 0 && arr[mid] >= key)
	{
		return 0;
	}

	return mid + 1;
}

//-----------------------------------------------------------------------------------------------------

int binary_search_increase_left(int *arr, int size, int key)
{
	int l = 0, r = size - 1, mid = (size - 1) / 2;

	while(l <= r)
	{
		if(arr[mid] <= key)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
		mid = (l + r) / 2;
	}
	if(mid == 0 && arr[mid] > key)
	{
		return 0;
	}	
	if(mid == size)
	{
		return size;
	}
	return mid + 1;
}
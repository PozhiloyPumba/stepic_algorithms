#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//=====================================================================================================

const int MAX = 10000;

//=====================================================================================================

void digital_sort(int *arr, int size);

void count_sort(int *arr, int *digits, int ten_in_power, int size);

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

	digital_sort(arr, n);

	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

//=====================================================================================================

void digital_sort(int *arr, int size)
{
	int number_of_digits = log10(MAX);

	int* tmp_arr = (int *)calloc(size, sizeof(int));
	int digits[10] = {};
	int ten_in_power = 1;
	
	for(int i = 0; i < number_of_digits; i++)
	{	
		if(i % 2 == 0)
		{
			count_sort(arr, digits, ten_in_power, size);

			for(int j = size - 1; j >= 0; j--)
			{
				tmp_arr[digits[(arr[j] / ten_in_power) % 10] - 1] = arr[j];
				digits[(arr[j] / ten_in_power) % 10]--;
			}
		}
		else
		{
			count_sort(tmp_arr, digits, ten_in_power, size);

			for(int j = size - 1; j >= 0; j--)
			{
				arr[digits[(tmp_arr[j] / ten_in_power) % 10] - 1] = tmp_arr[j];
				digits[(tmp_arr[j] / ten_in_power) % 10]--;
			}
		}
		
		ten_in_power *= 10;
		
		for(int j = 0; j < 10; j++)
		{
			digits[j] = 0;
		}
	}

	if(number_of_digits % 2 != 0)
	{
		for(int i = 0; i < size; i++)
		{
			arr[i] = tmp_arr[i];
		}
	}

	free(tmp_arr);
}

//-----------------------------------------------------------------------------------------------------

void count_sort(int *arr, int *digits, int ten_in_power, int size)
{
	for(int i = 0; i < size; i++)
	{
		digits[(arr[i] / ten_in_power) % 10]++;
	}

	for(int i = 1; i < 10; i++)
	{
		digits[i] += digits[i - 1];
	}
}

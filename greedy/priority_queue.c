#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//=====================================================================================================

struct heap_t{
	int *data;
	int size;
	int capacity;
};

//=====================================================================================================

struct heap_t *init_binary_heap();

void insert_binary_heap(struct heap_t *heap, int key);

int extract_max(struct heap_t *heap);

void destroy_binary_heap(struct heap_t *heap);

//=====================================================================================================

int main()
{
	char command[11];
	int count = 0, counter = 0;
	scanf("%d", &count);

	int *answers = (int *)calloc(count, sizeof(int));

	struct heap_t *heap = init_binary_heap();
	
	for (int i = 0; i < count; i++)
	{
		scanf("%s", command);
		if(command[1] == 'x')
		{
			answers[counter++] = extract_max(heap);
		}
		else
		{
			int key = 0;
			scanf("%d", &key);
			insert_binary_heap(heap, key);
		}
	}
	for(int i = 0; i < counter; i++)
	{
		printf("%d\n", answers[i]);
	}

	destroy_binary_heap(heap);

	return 0;
}

//=====================================================================================================

struct heap_t *init_binary_heap()
{
	struct heap_t *heap = (struct heap_t *)calloc(1, sizeof(struct heap_t));

	heap->capacity = 3;
	heap->size = 0;

	heap->data = (int *)calloc(3, sizeof(int));

	return heap;
}

//-----------------------------------------------------------------------------------------------------

void insert_binary_heap(struct heap_t *heap, int key)
{
	if(heap->size >= heap->capacity)
	{
		heap->data = (int *)realloc(heap->data, (heap->size * 2 + 1) * sizeof(int));
		heap->capacity = heap->size * 2 + 1;
	}

	int tmp = heap->size;
	heap->data[tmp] = key;

	while(tmp > 0 && key >= heap->data[(tmp - 1) / 2])
	{
		heap->data[tmp] = heap->data[(tmp - 1) / 2];
		heap->data[(tmp - 1) / 2] = key;
		tmp = (tmp - 1) / 2;
	}

	heap->size++;
}

//-----------------------------------------------------------------------------------------------------

int extract_max(struct heap_t *heap)
{
	assert(heap->size > 0);

	if(heap->size == 1)
	{
		heap->size--;
		return heap->data[0];
	}

	int max = heap->data[0];

	int tmp = 0;
	heap->size--;
	heap->data[0] = heap->data[heap->size];
 
	while(2 * tmp + 2 < heap->size)
	{
		int swap_tmp = heap->data[tmp];

		if(heap->data[2 * tmp + 2] > heap->data[2 * tmp + 1])
		{
			if(heap->data[2 * tmp + 2] > swap_tmp)
			{
				heap->data[tmp] = heap->data[2 * tmp + 2];
				heap->data[2 * tmp + 2] = swap_tmp;
				tmp = 2 * tmp + 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(heap->data[2 * tmp + 1] > swap_tmp)
			{
				heap->data[tmp] = heap->data[2 * tmp + 1];
				heap->data[2 * tmp + 1] = swap_tmp;
				tmp = 2 * tmp + 1;
			}
			else
			{
				break;
			}
		}
	}

	if(2 * tmp + 1 < heap->size)
	{
		if(heap->data[2 * tmp + 1] > heap->data[tmp])
		{
			int swap_tmp = heap->data[tmp];
			heap->data[tmp] = heap->data[2 * tmp + 1];
			heap->data[2 * tmp + 1] = swap_tmp;
		}
	}

	return max;
}

//-----------------------------------------------------------------------------------------------------

void destroy_binary_heap(struct heap_t *heap)
{
	free(heap->data);
	free(heap);
}

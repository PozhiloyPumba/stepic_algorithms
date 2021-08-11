#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//=====================================================================================================

struct node{
	char* sym;
	int freq;
	struct node *left;
	struct node *right;
};

struct heap_t{
	struct node **data;
	int size;
	int capacity;
};

struct buff_t{
	char *text;
	int size;
};

//=====================================================================================================

void filling_frequencies(struct buff_t *buffer, int *frequency);

void dump_frequences(int *frequency);

struct heap_t *init_binary_heap(int count);

struct heap_t *filling_heap(int *frequency);

void insert_binary_heap(struct heap_t *heap, int key, char sym);

int extract_max(struct heap_t *heap);

void destroy_binary_heap(struct heap_t *heap);

//=====================================================================================================

int main()
{
	int frequency[256] = {};
	struct buff_t buffer = {};
	buffer.text = (char *)calloc(10000, sizeof(char));

	buffer.size = fread(buffer.text, sizeof(char), 10000, stdin);

	filling_frequencies(&buffer, frequency);

	struct heap_t *heap = filling_heap(frequency);
	
	destroy_binary_heap(heap);

	return 0;
}

//=====================================================================================================

void filling_frequencies(struct buff_t *buffer, int *frequency)
{
	char *source = buffer->text;

	for(int i = 0; i < buffer->size; i++)
	{
		frequency[source[i]]++;
	}
	// dump_frequences(frequency);
}

//-----------------------------------------------------------------------------------------------------

void dump_frequences(int *frequency)
{
	FILE *output = fopen("dump_freq.txt", "w");

	for(int i = 0; i < 256; i++)
	{
		fprintf(output, "%c: %d\n", i, frequency[i]);
	}

	fclose(output);
}

//-----------------------------------------------------------------------------------------------------

struct heap_t *init_binary_heap(int count)
{
	struct heap_t *heap = (struct heap_t *)calloc(1, sizeof(struct heap_t));

	heap->capacity = 1;
	heap->size = 0;

	heap->data = (struct node **)calloc(count, sizeof(struct node *));

	return heap;
}

//-----------------------------------------------------------------------------------------------------

struct heap_t *filling_heap(int *frequency)
{
	int count = 0;
	for(int i = 0; i < 256; i++)
	{
		if(frequency[i])
		{
			count++;
		}
	}

	struct heap_t *heap = init_binary_heap(count);
	
	for(int i = 0; i < 256; i++)
	{
		if(frequency[i])
		{
			struct node *elem = (struct node *)calloc(1, sizeof(struct node));
			
		}
	}
}

//-----------------------------------------------------------------------------------------------------

void insert_binary_heap(struct heap_t *heap, int key, char sym)
{
	if(heap->size >= heap->capacity)
	{
		heap->data = (struct node *)realloc(heap->data, (heap->size * 2 + 1) * sizeof(struct node));
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

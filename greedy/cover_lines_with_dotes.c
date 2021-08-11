#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------------------------

struct segment{
	int left, right;
};

//-----------------------------------------------------------------------------------------------------

int comparator(const void *x1, const void *x2);

int get_covering_set(struct segment *lines, int *dots, int count);

//-----------------------------------------------------------------------------------------------------

int main()
{
	int count = 0;
	scanf("%d", &count);

	struct segment *lines = (struct segment *)calloc(count, sizeof(struct segment));
	int *dots = (int *)calloc(count, sizeof(int));

	for (size_t i = 0; i < count; i++)
	{
		scanf("%d%d", &lines[i].left, &lines[i].right);
	}

	qsort(lines, count, sizeof(struct segment), &comparator);

	int count_dots = get_covering_set(lines, dots, count);

	printf("%d\n", count_dots);
	for (size_t i = 0; i < count_dots; i++)
	{
		printf("%d ", dots[i]);
	}
	printf("\n");

	free(lines);
	free(dots);
	
	return 0;
}

//-----------------------------------------------------------------------------------------------------

int comparator(const void *x1, const void *x2)
{
	return ((struct segment *) x1)->right - ((struct segment *) x2)->right;
}

//-----------------------------------------------------------------------------------------------------

int get_covering_set(struct segment *lines, int *dots, int count)
{
	int count_dots = 0;

	for (size_t i = 0; i < count; i++)
	{
		dots[count_dots] = lines[i].right;
		
		int flag = 0;
		while (i < count && lines[i].left <= dots[count_dots])
		{
			i++;
			flag = 1;
		}
		if (flag)
		{
			i--;
		}
		
		count_dots++;
	}
	
	return count_dots;
}

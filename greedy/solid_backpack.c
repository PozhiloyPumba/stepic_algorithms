#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------------------------------

struct part{
	double cost, volume;
	double price;
};

//-----------------------------------------------------------------------------------------------------

int comparator(const void *x1, const void *x2);

double fill_the_backpack(struct part *things, int count, int capacity);

//-----------------------------------------------------------------------------------------------------

int main()
{
	int count = 0, capacity = 0;
	scanf("%d%d", &count, &capacity);

	struct part *things = (struct part *)calloc(count, sizeof(struct part));

	for (int i = 0; i < count; i++)
	{
		scanf("%lg%lg", &things[i].cost, &things[i].volume);
		things[i].price = things[i].cost / things[i].volume;
	}

	qsort(things, count, sizeof(struct part), &comparator);

	printf("%.3lf\n", fill_the_backpack(things, count, capacity));

	free(things);
	
	return 0;
}

//-----------------------------------------------------------------------------------------------------

int comparator(const void *x1, const void *x2)
{
	return ((struct part *) x2)->price > ((struct part *) x1)->price?1:-1;
}

//-----------------------------------------------------------------------------------------------------

double fill_the_backpack(struct part *things, int count, int capacity)
{
	double backpack_price = 0;
	double current_volume_free = (double)capacity;

	for (int i = 0; i < count; i++)
	{
		if(things[i].volume < current_volume_free)
		{
			backpack_price += things[i].cost;
			current_volume_free -= things[i].volume;
		}
		else
		{
			backpack_price += (current_volume_free * things[i].price);
			return backpack_price;
		}
	}

	return backpack_price;
}

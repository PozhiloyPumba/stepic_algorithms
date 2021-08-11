#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//-----------------------------------------------------------------------------------------------------

int main()
{
	unsigned long long n = 0;
	scanf("%llu", &n);

	unsigned long long last = (-1 + sqrt(1 + 8 * n)) / 2;

	printf("%llu\n", last);
	
	for(unsigned long long i = 1; i < last; i++)
	{
		printf("%llu ", i);
	}
	printf("%llu\n", n - (last - 1) * last / 2);

	return 0;
}
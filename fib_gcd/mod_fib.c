#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int mod_fib(unsigned long long n, int m);

int main()
{
	unsigned long long n = 0;
	int m = 0;
	scanf("%llu%d", &n, &m);

	printf("\n%d\n", mod_fib(n, m));

	return 0;
}

int mod_fib(unsigned long long n, int m)
{
	assert(n > 0 && m > 1);
	
	if(n == 1 || n == 2)
		return 1;

	int *pizano = (int *) calloc(m * 6 + 1, sizeof(int));

	int i = 1;
	pizano[0] = pizano[1] = 1;
	
	for(; pizano[i - 1] != 0 || pizano[i] != 1; i++)
	{
		pizano[i + 1] = (pizano[i - 1] + pizano[i]) % m;
		printf("%d ", pizano[i - 1]);
	}

	int mod = pizano[(n - 1) % i];

	free(pizano);
	return mod;
}
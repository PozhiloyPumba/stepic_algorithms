#include <stdio.h>
#include <assert.h>

unsigned long long fib();

int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%llu\n", fib(n));

	return 0;
}

unsigned long long fib(int n)
{
	assert(n > 0);
	unsigned long long answer = 1, a = 1;
	
	if(n == 1 || n == 2)
		return 1;

	for(int i = 2; i < n; i++)
	{
		answer += a;
		a = answer - a;
		printf("%d: %llu\n", i + 1, answer);
	}

	return answer;
}
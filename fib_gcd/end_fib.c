#include <stdio.h>
#include <assert.h>

int end_fib(int n);

int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d\n", end_fib(n));

	return 0;
}

int end_fib(int n)
{
	assert(n > 0);
	int answer = 1, a = 1;
	
	if(n == 1 || n == 2)
		return 1;

	for(int i = 2; i < n; i++)
	{
		answer += a;
		a = (answer - a) % 10;
	}

	return answer % 10;
}
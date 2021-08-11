#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b);

int main()
{
	unsigned long long a = 0, b = 0;
	
	scanf("%llu%llu", &a, &b);
	
	printf("%llu\n", gcd(a, b));
	
	return 0;
}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if(a >= b)
	{
		if(b == 0)
			return a;

		return gcd(a % b, b);
	}
	else
	{
		if(a == 0)
			return b;
		
		return gcd(b % a, a);
	}
	return 0;
}

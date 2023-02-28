#include <stdio.h>

int main()
{
	long long n;
	long long p = 1;
	scanf_s("%lld", &n);
	if (n == 1 || n == -1)
	{
		printf("%lld\n", 1);
		return 0;
	}
	if (n >= 0)
	{
		while (p <= 1000000000)
		{
			printf("%lld\n", p);
			if (p * n > 1000000000)
			{
				return 0;
			}
			else
			{
				p *= n;
			}
		}
	}
	else
	{
		while (p <= 1000000000)
		{
			printf("%lld\n", p);
			if (p * n * n > 1000000000)
			{
				return 0;
			}
			else
			{
				p *= n * n;
			}
		}
	}
}

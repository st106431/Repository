#include <iostream>
#include <algorithm>
using namespace std;

bool prime(long long n)
{
	if (n < 2)
	{
		return false;
	}
	for (long long d = 2; d * d <= n; d++)
	{
		if ((n % d) == 0)
		{
			return false;
		}
	}
	return true;
}

int exp(int n, int p)
{
	int k = 0;
	while ((n % p) == 0)
	{
		n /= p;
		k++;
	}
	return k;
}

int main()
{
	long long n;
	long long cb;
	long long i = 1;
	int j = 0;
	cin >> n;
	int number = 1;
	int pri = 0;
	int k = 1;
	long long* s_p;
	if (n >= 10000)
	{
		cb = cbrt(n);
		s_p = new long long[cb];
		cout << cb;
		for (long long i = 1; i <= cb; i++)
		{
			if (prime(i) == 1)
			{
				s_p[pri] = i;
				pri++;
			}
		}
	}
	else
	{
		s_p = new long long[max(n, (long long)4)];
		for (long long i = 1; i <= max(sqrt(n), 10.0); i++)
		{
			if (prime(i) == 1)
			{
				s_p[pri] = i;
				pri++;
			}
		}
	}
while (i < n)
{
	if ((i * s_p[i]) <= n)
	{
		i *= s_p[j];
		number = (number * (k + 1)) / k;
		if (j < (pri - 1))
		{
			j++;
		}
		else
		{
			j = 0;
			k++;
		}
	}
	else
	{
		if ((2 * i) <= n)
		{
			j = 0;
			k++;
		}
		else
		{
			break;
		}
	}
}
cout << number;
}

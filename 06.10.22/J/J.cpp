#include <iostream>
#include <map>
using namespace std;

long long phi(long long n)
{
	long long res = n;
	for (long long d = 2; d * d <= n; d++)
	{
		if (n % d == 0)
		{
			res = (res / d) * (d - 1);
			while (n % d == 0)
			{
				n /= d;
			}
		}
	}
	if (n > 1)
	{
		res = (res / n) * (n - 1);
	}
	return res;
}

long long powMod(long long a, long long r, long long m) 
{
	long long res = 1 % m;
	for (; r > 0; r >>= 1) 
	{
		if (r & 1)
		{
			res = (res * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
	}
	return res;
}

long long discrete_log(long long a, long long b, long long p)
{
	long long phi_p = p - 1;
	long long lim = (long long)(sqrt(phi_p)) + 1;
	map <long long, long long> power;
	long long a_lim = 1;
	for (long long i = 0; i < lim; i++) 
	{
		power[a_lim] = i;
		a_lim = (a_lim * 1LL * a) % p;
	}
	for (long long i = 0; i < lim; i++)
	{
		if (power.count(b))
		{
			return (power[b] - i * lim + phi_p) % phi_p;
		}
		b = (b * 1LL * a_lim) % p;
	}
	return -1;
}

int main()
{
	long long a, b, n;
	cin >> a >> b >> n;
	cout << discrete_log(a, b, n);
	//cout << powMod(a, b, n);
}
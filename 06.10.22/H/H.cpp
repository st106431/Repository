#include <iostream>
#include <map>
using namespace std;

long long powMod(long long a, long long b, long long m)
{
	long long res = 1 % m;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
		{
			res = (res * 1LL * (a % m)) % m;
		}
		a = ((a % m) * 1LL * (a % m)) % m;
	}
	return res;
}

bool prime(long long n)
{
	if (n < 2)
	{
		return false;
	}
	for (long long d = 2; d * d <= n; d++)
	{
		if (n % d == 0)
		{
			return false;
		}
	}
	return true;
}

bool check(long long a, int* f, int l, long long p)
{
	if (a % p == 0)
	{
		return 0;
	}
	for (int j = 0; j < l; j++)
	{
		if (powMod(a, (long long)f[j], p) == 1)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	long long p;
	int l = 0;
	cin >> n >> p;
	int* mas = new int[n];
	int* fact = new int[(p - 1) / 2];
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	for (long long i = 2; i <= (p - 1) / 2; i++)
	{
		if ((((p - 1) % i) == 0) && (prime(i)))
		{
			fact[l] = (p - 1) / i;
			l++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (check(mas[i], fact, l, p))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

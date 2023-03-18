#include <iostream>
using namespace std;

int phi(int n) 
{
	int res = n;
	for (int d = 2; d * d <= n; d++) 
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

int powMod(int a, int b, int m) 
{
	int res = 1 % m;
	for (; b > 0; b >>= 1) 
	{
		if (b & 1)
		{
			res = (res * 1LL * a) % m;
		}
		a = (a * 1LL * a) % m;
	}
	return res;
}

int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}

int main()
{
	int n, p;
	cin >> n >> p;
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	if (gcd(p, n) == 1)
	{
		cout << powMod(p, phi(n) - 1, n);
	}
	else
	{
		cout << -1;
	}
}
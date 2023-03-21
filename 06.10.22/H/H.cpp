#include <iostream>
using namespace std;

long long powMod(long long a, int b, long long m)
{
	long long res = 1 % m;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
		{
			res = (res * 1LL * (a % m)) % m;
		}
		a = a % m;
		a = (a * 1LL * a) % m;
	}
	return res;
}

int r(long long n, int* tr, int pos)
{
	if (n != 1)
	{
		int i = 2;
		while ((n % i) != 0)
		{
			i++;
		}
		tr[pos] = i;
		while (n % i == 0)
		{
			n /= i;
		}
		pos++;
		r(n, tr, pos);
	}
	else
	{
		return pos;
	}
}

bool check(long long a, int* f, int l, long long p)
{
	if ((a % p) == 0)
	{
		return 0;
	}
	for (int j = 0; j < l; j++)
	{
		if (powMod(a, f[j], p) == 1)
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
	int pos = 0;
	cin >> n >> p;
	int* mas = new int[n];
	int* fact = new int[log2(p - 1)];
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	if (p != 3)
	{
		l = r(p - 1, fact, pos);
	}
	else
	{
		fact[0] = 1;
		l = 1;
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

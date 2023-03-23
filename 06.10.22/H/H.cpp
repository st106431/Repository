#include <iostream>
#include <vector>
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
		a = a % m;
		a = (a * 1LL * a) % m;
	}
	return res;
}

bool check(long long a, vector <long long> f, int l, long long p)
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
	cin >> n >> p;
	int* mas = new int[n];
	long long w = p - 1;
	vector <long long> fact;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	if (p != 3)
	{
		long long i = 2;
		while (i * i <= w)
		{
			if ((w % i) == 0)
			{
				fact.push_back((p - 1) / i);
				l++;
				while ((w % i) == 0)
				{
					w /= i;
				}
			}
			i++;
		}
		if (w != 1)
		{
			fact.push_back((p - 1) / w);
			l++;
		}
	}
	else
	{
		fact.push_back(1);
		l = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (check((long long)mas[i], fact, l, p))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

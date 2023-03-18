#include <iostream>
#include <math.h> 
using namespace std;

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

long long rem(long long e)
{
	long long t = (long long)cbrt(e);
	return (e - (t * t * t)) % t;
}

long long quo(long long e_0)
{
	long long t_0 = (long long)cbrt(e_0);
	return ((e_0 - t_0 * t_0 * t_0) / t_0);
}

long long powMod(long long a, long long b, long long m)
{
	long long h, temp, cb;
	long long res = 1 % m;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
		{
			h = res % m;
			if (a != 0)
			{
				cb = (long long)cbrt(a);
				res = (res * 1LL * cb) % m;
				res = (res * 1LL * cb) % m;
				res = (res * 1LL * cb) % m;
				temp = res;
				res = (res * 1LL * cb) % m;
				res = (res * 1LL * (((a - (cb * cb * cb)) / cb) % m)) % m;
				res = (res + (temp * ((a - (cb * cb * cb)) % cb))) % m; 
			}
			else
			{
				res = 0;
			}
		}
		h = a % m;
		cb = (long long)cbrt(a);
		if (a != 0)
		{
			h = (h * 1LL * cb) % m;
			h = (h * 1LL * cb) % m;
			h = (h * 1LL * cb) % m;
			temp = h;
			h = (h * 1LL * cb) % m;
			h = (h * 1LL * (((a - (cb * cb * cb)) / cb) % m)) % m;
			h = (h + (temp * ((a - (cb * cb * cb)) % cb))) % m;
			a = h;
			cout << a;
		}
	}
	return res;
}

bool M_R(long long a, long long r, long long N)
{
	if ((r % 2) == 0)
	{
		if (powMod(a, r, N) == (N - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (powMod(a, r, N) == 1 || powMod(a, r, N) == (N - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	long long n, w;
	cin >> n;
	w = n - 1;
	if ((n == 1) || ((n % 2) == 0))
	{
		cout << -1;
		return 0;
	}
	if (prime(n))
	{
		cout << 0;
		return 0;
	}
	long long buff[60];
	int i = 0;
	while ((w % 2) == 0)
	{
		w /= 2;
		buff[i] = w;
		i++;
	}
	long long s[8];
	s[0] = 2;
	s[1] = 3;
	s[2] = 5;
	s[3] = 7;
	s[4] = 11;
	s[5] = 13;
	s[6] = 17;
	s[7] = 19;
	int count;
	for (int k = 0; k < 8; k++)
	{
		count = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (M_R(s[k], buff[j], n) == 0)
			{
				count++;
			}
		}
		if (count == i)
		{
			cout << s[k];
			return 0;
		}
	}
	cout << 0;
}
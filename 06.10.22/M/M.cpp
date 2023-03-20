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
	return (e % 10000);
}

long long quo(long long e_0)
{
	return (e_0 / 10000);
}

long long mult(long long y, long long t, long long m)
{
	if (t == 0)
	{
		return 0;
	}
	if (t == 1)
	{
		return y % m;
	}
	else
	{
		long long pr = mult(y, t / 2, m);
		if (t % 2 == 0)
		{
			return (pr + pr) % m;
		}
		else
		{
			return (((pr + pr) % m) + (y % m)) % m;
		}
	}
}

long long powMod(long long a, long long b, long long m)
{
	long long h, temp;
	long long res = 1 % m;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
		{
			h = res % m;
			if (a != 0)
			{
				temp = res % m;
				res = temp;
				res = mult(res, quo(a), m);
				res = mult(res, 10, m);
				res = mult(res, 10, m);
				res = mult(res, 10, m);
				res = mult(res, 10, m);
				res = (res + mult(temp, rem(a), m)) % m;
			}
			else
			{
				res = 0;
			}
		}
		h = a % m;
		if (a != 0)
		{
			temp = a;
			a = a % m;
			a = mult(a, quo(a), m);
			a = mult(a, 10, m);
			a = mult(a, 10, m);
			a = mult(a, 10, m);
			a = mult(a, 10, m);
			a = (a + mult((temp % m), rem(temp), m)) % m;
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
	if (n == 1)
	{
		cout << "NO";
		return 0;
	}
	if (((n % 2) == 0) && (n != 2))
	{
		cout << "NO";
		return 0;
	}
	if (n == 2)
	{
		cout << "YES";
		return 0;
	}
	long long buff[65];
	int i = 0;
	while ((w % 2) == 0)
	{
		w /= 2;
		buff[i] = w;
		i++;
	}
	long long s[11];
	s[0] = 2;
	s[1] = 3;
	s[2] = 5;
	s[3] = 7;
	s[4] = 11;
	s[5] = 13;
	s[6] = 17;
	s[7] = 19;
	s[8] = 23;
	for (int q = 0; q < 9; q++)
	{
		if (n == s[q])
		{
			cout << "YES";
			return 0;
		}
	}
	int count;
	for (int k = 0; k < 9; k++)
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
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
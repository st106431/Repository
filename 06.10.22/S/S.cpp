#include <iostream>
using namespace std;

long long mulMod(long long a, long long b, long long m)
{
	long long res = 0;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
		{
			res = (res + a) % m;
		}
		a = (a + a) % m;
	}
	return res;
}


long long** mult(long long** m_1, long long k, long long m)
{
	if (k == 1)
	{
		return m_1;
	}
	long long sum;
	long long** res = mult(m_1, k - 1, m);
	long long** ip = new long long* [2];
	for (int i = 0; i < 2; i++)
	{
		ip[i] = new long long[2];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum = 0;
			for (int k = 0; k < 2; k++)
			{
				sum = (sum + (mulMod(m_1[i][k], res[k][j], m))) % m;
			}
			ip[i][j] = sum;
		}
	}
	return ip;
}

long long** q_mult(long long** m_1, long long k, long long m)
{
	if (k == 1)
	{
		return m_1;
	}
	if (k % 2 == 0)
	{
		return mult(q_mult(m_1, k / 2, m), 2, m);
	}
	else
	{
		long long** t = mult(q_mult(m_1, k / 2, m), 2, m);
		long long sum;
		long long** ip = new long long* [2];
		for (int i = 0; i < 2; i++)
		{
			ip[i] = new long long[2];
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum = (sum + (mulMod(m_1[i][k], t[k][j], m))) % m;
				}
				ip[i][j] = sum;
			}
		}
		return ip;
	}
}

int main()
{
	long long n;
	long long m;
	cin >> n >> m;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	if (n == 1)
	{
		if (m != 1)
		{
			cout << 1;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	long long** mx = new long long* [2];
	for (int i = 0; i < 2; i++)
	{
		mx[i] = new long long[2];
	}
	mx[0][0] = 1;
	mx[0][1] = 1;
	mx[1][0] = 1;
	mx[1][1] = 0;
	mx = q_mult(mx, n - 1, m);
	cout << mx[0][0];
}
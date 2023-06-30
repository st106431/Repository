#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <complex>
#include <iomanip>
#include <set>
using namespace std;

long long const logLimit = 19;
long long const limit = 1 << logLimit;
vector <int> rev;

void calcRev()
{
	rev = vector <int>(limit, 0);
	for (int i = 0; i < limit; i++)
	{
		for (int k = 0; k < logLimit; k++)
		{
			if (i & (1 << k))
			{
				rev[i] ^= 1 << (logLimit - k - 1);
			}
		}
	}
}

using Num = complex <long double>;

long double const Pi = acos(-1.0);

vector <Num> z;

void calcZ()
{
	z = vector <Num>(limit);
	for (int i = 0; i < limit; i++)
	{
		z[i] = Num(cos((long double)i * 2.0 * Pi / limit), sin((long double)i * 2.0 * Pi / limit));
	}
}

vector <Num> fft(const vector <Num>& a0, bool inv = false)
{
	vector <Num> a = a0;
	for (int i = 0; i < limit; i++)
	{
		if (i < rev[i])
		{
			swap(a[i], a[rev[i]]);
		}
	}
	if (inv)
	{
		reverse(z.begin() + 1, z.end());
	}
	for (long long k = 0, span = 1, step = limit / 2; k < logLimit; k++, span *= 2, step /= 2)
	{
		for (long long i = 0; i < limit; i += 2 * span)
		{
			for (long long j = 0; j < span; j++)
			{
				long long u = i + j;
				long long v = i + j + span;
				Num x = a[u] + a[v] * z[j * step];
				Num y = a[u] + a[v] * z[j * step + limit / 2];
				a[u] = x;
				a[v] = y;
			}
		}
	}
	if (inv)
	{
		reverse(z.begin() + 1, z.end());
		for (int i = 0; i < limit; i++)
		{
			a[i] /= limit;
		}
	}
	return a;
}

int main()
{
	calcRev();
	calcZ();
	string t;
	int z = 1;
	int w = 1;
	cin >> t;
	vector <Num> a(limit, Num(0));
	vector <Num> b(limit, Num(0));
	if (t[0] == '-')
	{
		z = -1;
		t = t.substr(1);
		for (int i = 0; i < t.length(); i++)
		{
			a[i] = Num((int)t[t.length() - 1 - i] - 48);
		}
	}
	else
	{
		for (int i = 0; i < t.length(); i++)
		{
			a[i] = Num((int)t[t.length() - 1 - i] - 48);
		}
	}
	cin >> t;
	if (t[0] != '-')
	{
		for (int i = 0; i < t.length(); i++)
		{
			b[i] = Num((int)t[t.length() - 1 - i] - 48);
		}
	}
	else
	{
		w = -1;
		t = t.substr(1);
		for (int i = 0; i < t.length(); i++)
		{
			b[i] = Num((int)t[t.length() - 1 - i] - 48);
		}
	}
	auto res_1 = fft(a);
	auto res_2 = fft(b);
	vector<Num>res(res_1.size(), Num(0));
	for (int i = 0; i < res_1.size(); i++)
	{
		res[i] = res_1[i] * res_2[i];
	}
	auto p = fft(res, true);
	vector <int> res_0(limit);
	long long temp = 0;
	for (int i = 0; i < limit; i++) 
	{
		temp += (long long)(abs(p[i].real()) + 0.5);
		res_0[i] = temp % 10;
		temp /= 10;
	}
	bool start = false;
	long long d = 0;
	for (int i = 0; i < limit; i++)
	{
		if (abs(p[i].real()) > pow(10.0, -10))
		{
			d++;
		}
	}
	if (z * w == -1 && d > 0)
	{
		cout << '-';
	}
	for (long long i = limit - 1; i >= 0; i--) 
	{
		start |= (i == 0) | (res_0[i] != 0);
		if (start)
		{
			cout << res_0[i];
		}
	}
}
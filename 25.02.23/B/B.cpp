#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
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

vector <Num> fft(const vector <Num> & a0, bool inv = false)
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
	string s;
	cin >> s;
	vector <Num> a(limit, Num(0));
	for (int i = 0; i < s.length(); i++)
	{
		a[i] = Num((int)s[i] - 48);
	}
	auto res = fft(a);
	for (int i = 0; i < res.size(); i++)
	{
		res[i] = res[i] * res[i];
	}
	auto p = fft(res, true);
	long long sum = 0;
	for (long long i = 0; i < p.size(); i++)
	{
		if (((long long)(ceil(p[i].real())) % 2) == 1)
		{
			sum += (long long)ceil(p[i].real()) / 2;
		}
	}
	cout << sum;
}
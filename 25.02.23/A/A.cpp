#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

long long const logLimit = 20;
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
		z[i] = Num(cos(i * 2 * Pi / limit), sin(i * 2 * Pi / limit));
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
	for (long double k = 0, span = 1, step = static_cast<long double>(limit) / 2; k < logLimit; k++, span *= 2, step /= 2)
	{
		for (int i = 0; i < limit; i += 2 * span)
		{
			for (int j = 0; j < span; j++)
			{
				int u = i + j;
				int v = i + j + span;
				Num x = a[u] + a[v] * z[j * step];
				Num y = a[u] + a[v] * z[j * step + static_cast<long double>(limit) / 2];
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
	long double n;
	long double t;
	vector <Num> a (limit, Num(0));
	cin >> n;
	long double* s = new long double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		t = (long double)60000 + s[i];
		a[t] = Num(1);
	}
	auto res = fft(a);
	for (int i = 0; i < res.size(); i++)
	{
		res[i] = res[i] * res[i];
	}
	auto p = fft(res, true);
	int k = -1;
	Num (max) = p[0];
	cout << p.size();
	return 0;
	for (long long i = 0; i <= p.size(); i += 2)
	{
		if (p[i].real() > max.real())
		{
			max = p[i];
		}
	}
	cout << max;
}

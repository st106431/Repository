#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
	int n;
	long long t;
	vector <Num> a (limit, Num(0));
	cin >> n;
	long long* s = new long long[n];
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		t = s[i] + (long long)60000;
		a[t] = Num(1);
	}
	auto res = fft(a);
	for (int i = 0; i < res.size(); i++)
	{
		res[i] = res[i] * res[i];
	}
	auto p = fft(res, true);
	int k = 0;
	long double max = p[0].real();
	for (long long i = 0; i < p.size(); i++)
	{
		if (p[i].real() > max)
		{
			max = p[i].real();
			k = i;
		}
	}
	double y = k / 2.0 - (double)60000;
	cout << fixed << setprecision(1) << y << endl;
	if (((long long)max % 2) == 0)
	{
		cout << fixed << setprecision(0) << max / 2 << endl;
	}
	else
	{
		cout << fixed << setprecision(0) << (max + 1) / 2 << endl;
	}
	for (int i = 0; i <= k / 2; i++)
	{
		if (a[i] * a[k - i] == Num(1))
		{
			cout << fixed << setprecision(1) << abs(y - (double)i + (double)60000) << " ";
		}
	}
}

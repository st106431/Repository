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

vector <Num> interpret(string t)
{
	vector <Num> temp(limit, Num(0));
	int y = 0;
	pair <int, int> p = make_pair(-1, -1);
	int degree = 0;
	for (int i = t.length() - 1; i >= 0; i--)
	{
		if (t[i] != ' ' && t[i] != '+')
		{
			if (t[i] == '-')
			{
				if (p.first != -1 && p.second != -1)
				{
					p.first = -p.first;
					temp[p.second] = p.first;
				}
				if (p.first == -1)
				{
					p.first = -1;
				}
				if (p.second == -1)
				{
					p.second = 1;
				}
			}
			else
			{
				if (t[i] == 'x')
				{
					if (i != 0 && i != t.length() - 1)
					{
						if (t[i - 1] == ' ' && t[i + 1] == ' ')
						{
							p.first = 1;
							p.second = 1;
						}
					}
					if (i == 0)
					{
						if (t[i + 1] == ' ')
						{
							p.first = 1;
							p.second = 1;
						}
					}
					if (i == t.length() - 1)
					{
						if (t[i - 1] == ' ')
						{
							p.first = 1;
							p.second = 1;
						}
					}
				}
				if (t[i] != 'x' && t[i] != '^')
				{
					if (i != 0)
					{
						if (t[i - 1] == ' ')
						{
							p.first = (int)t[i] - 48;
						}
						else
						{
							p.second = (int)t[i] - 48;
						}
					}
					else
					{
						p.first = (int)t[i] - 48;
					}
				}
			}
		}
	}
}

int main()
{
	calcRev();
	calcZ();
	string t;
	cin >> t;
	vector <Num> a(limit, Num(0));
	vector <Num> b(limit, Num(0));
	a = interpret(t);
	cin >> t;
	b = interpret(t);
	auto res_1 = fft(a);
	auto res_2 = fft(b);
	vector<Num>res(res_1.size(), Num(0));
	for (int i = 0; i < res_1.size(); i++)
	{
		res[i] = res_1[i] * res_2[i];
	}
	auto p = fft(res, true);
}
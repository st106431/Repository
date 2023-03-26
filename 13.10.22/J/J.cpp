#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
using namespace std;

const long double C = sqrt(2 * acos(-1.0));

long double func(long double x)
{
	return exp(-x * (x / 2)) / C;
}

long double integral(long double a, long double b, long long n)
{
	long double sum;
	long double d = (b - a) / (long double)n;
	long double x = a + d;
	sum = 0.0;
	mt19937 rng(1374883);
	while (x <= b)
	{
		uniform_int_distribution <long long> random(1, 1000000);
		sum += func(x - (d / (long double)random(rng))) * d;
		x += d;
		if (x > b)
		{
			break;
		}
	}
	return sum;
}

int main()
{
	long double p, q, x_0;
	cin >> p >> q;
	x_0 = p / q;
	long double res = integral((long double) - 100.1, (long double)-1.0, (long double)10000000) + integral((long double)-1.0, (long double)0.0, (long double)10000000) + integral((long double)0.0, (long double)x_0 / 2.0, (long double)10000000) + integral((long double)x_0 / 2.0, x_0, (long double)10000000);
	cout << fixed << setprecision(12) << res;
}
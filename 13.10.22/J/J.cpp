#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
using namespace std;

const long double C = sqrt((long double)2 * acos((long double) - 1.0));

long double func(long double x)
{
	return exp(-x * (x / 2)) / C;
}

long double integral(long double a, long double b, long long n)
{
	long double sum;
	long double d = (b - a) / (long double)n;
	long double x = a;
	sum = 0.0;
	while (x <= b)
	{
		if(x == a || x == b)
		{
			sum += func(x) / 2;
			x += d;
		}
		else
		{
			sum += func(x);
			x += d;
		}
	}
	sum *= d;
	return sum;
}

int main()
{
	long double p, q, x_0;
	cin >> p >> q;
	x_0 = p / q;
	long double res = integral((long double)-10, (long double)x_0, (long long)10000000);
	cout << fixed << setprecision(13) << res;
}
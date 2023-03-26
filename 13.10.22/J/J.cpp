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
	long double x = a + d;
	sum = 0.0;
	for (int i = 1; i < n; i++)
	{
			sum += func(x);
			x += d;
	}
	sum += func(a) / 2 + func(b) / 2;
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
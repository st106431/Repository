#include <iostream>
#include <iomanip>
using namespace std;

long double triangle(long double x_1, long double y_1, long double x_2, long double y_2, long double x_3, long double y_3)
{
	x_2 -= x_1;
	x_3 -= x_1;
	y_2 -= y_1;
	y_3 -= y_1;
	long double s = abs(x_2 * y_3 - x_3 * y_2);
	return s / 2;
}

int main()
{
	int n;
	cin >> n;
	long double* x = new long double[n];
	long double* y = new long double[n];
	long double s = 0.0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n - 2; i++)
	{
		s += triangle(x[i + 1], y[i + 1], x[i + 2], y[i + 2], x[0], y[0]);
	}
	cout << fixed << setprecision(10) << s;
}
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const long double C = sqrt(2 * acos(-1.0));
const int N = 200;

double sum(long double x, long double y, long double* s)
{
	long double sum = 0.00;
	for (int i = 0; i < N; i++)
	{
		sum += s[i] * (pow((long double)x, (2 * i) + 1) - s[i] * pow((long double)y, (2 * i + 1)));
		cout << sum << endl;
	}
	return sum;
}

int main()
{
	long double p, q, x_0;
	cin >> p >> q;
	x_0 = p / q;
	long double* s = new long double[N];
	s[0] = 1.0;
	for (int i = 1; i < N; i++)
	{
		s[i] = (s[i - 1] * (2 * (long double)i - 1)) / ((2 * (long double)i) * (long double)(2 * i + 1));
		if ((i % 2) != 0)
		{
			s[i] = -s[i];
		}
	}
	long double res = sum(x_0, 3.8, s) / C;
	cout << fixed << setprecision(10) << res;
	//cout << res;
}
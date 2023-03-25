#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double C = 1 / sqrt(2 * acos(-1.0));

double sum(double x, double y, double* s)
{
	double sum = 0.0;
	for (int i = 0; i < 15; i++)
	{
		//cout << s[i] * (pow(x, (2 * i) + 1) - pow(y, (2 * i + 1))) << endl;
		sum += s[i] * (pow(x, (2 * i) + 1) - pow(y, (2 * i + 1)));
		cout << sum << endl;
	}
	return sum;
}

int main()
{
	double p, q, x_0;
	double pr;
	cin >> p >> q;
	x_0 = p / q;
	double* s = new double[15];
	pr = 1.0;
	for (int i = 0; i < 15; i++)
	{
		s[i] = 1.0 / ((pow(2, i) * pr) * (2 * i + 1));
		if ((i % 2) != 0)
		{
			s[i] = -s[i];
		}
		pr *= i + 1;
	}
	double res = sum(x_0, -100.8, s) / C;
	//cout << fixed << setprecision(4) << res;
	cout << res;
}
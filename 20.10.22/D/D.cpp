#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

pair<long double, long double> solve(long double a, long double b, long double c)
{
	long double D = b * b - 4 * a * c;
	pair <long double, long double>p = make_pair((-b - sqrt(D)) / (2 * a), (sqrt(D) - b) / (2 * a));
	return p;
}

void number(long double x_1, long double y_1, long double r_1, long double x_2, long double y_2, long double r_2)
{
	if (x_1 == x_2 && y_1 == y_2)
	{
		if (r_1 != r_2)
		{
			cout << "There are no points!!!" << endl << endl;
			return;
		}
		else
		{
			cout << "I can't count them - too many points :(" << endl << endl;
			return;
		}
	}
	long double d = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
	if (d >= r_1 && d >= r_2)
	{
		if (r_1 + r_2 < d)
		{
			cout << "There are no points!!!" << endl << endl;
			return;
		}
		if (r_1 + r_2 == d)
		{
			cout << "There are only 1 of them...." << endl;
			cout << fixed << setprecision(6) << (r_1 * x_1 + r_2 * x_2) / d << " " << (r_1 * y_1 + r_2 * y_2) / d << endl << endl;
			return;
		}
		if (r_1 + r_2 > d)
		{
			cout << "There are only 2 of them...." << endl;
			long double c = x_2 * x_2 + y_2 * y_2 - r_2 * r_2;
			long double A = x_1 * x_1 + y_1 * y_1 - r_1 * r_1;
			long double B = c - 2 * x_2 * x_2 + 2 * x_1 * x_2 - A;
			long double q = 4 * (x_2 - x_1) * (x_2 - x_1) * (x_2 * x_2 - c);
			auto p = solve(-4 * d * d, 8 * (x_1 - x_2) * (x_1 - x_2) * y_2 - 4 * (y_1 - y_2) * B, q - B * B);
			long double x = x_2 - sqrt(x_2 * x_2 - p.first * p.first + 2 * p.first * y_2 - c);
			long double z = x_2 - sqrt(x_2 * x_2 - p.second * p.second + 2 * p.second * y_2 - c);
			if (x == z)
			{
				cout << fixed << setprecision(6) << x << " " << min(p.first, p.second) << endl;
				cout << fixed << setprecision(6) << z << " " << max(p.first, p.second) << endl << endl;
				return;
			}
			if (x < z)
			{
				cout << fixed << setprecision(6) << x << " " << p.first << endl;
				cout << fixed << setprecision(6) << z << " " << p.second << endl << endl;
				return;
			}
			else
			{
				cout << fixed << setprecision(6) << z << " " << p.second << endl;
				cout << fixed << setprecision(6) << x << " " << p.first << endl << endl;
				return;
			}
		}
	}
	else
	{
		if (abs(r_1 - r_2) > d)
		{
			cout << "There are no points!!!" << endl << endl;
			return;
		}
		if (abs(r_1 - r_2) == d)
		{
			cout << "There are only 1 of them...." << endl;
			cout << fixed << setprecision(6) << (r_1 * x_2 - r_2 * x_1) / d << " " << (r_1 * y_2 - r_2 * y_1) / d << endl << endl;
			return;
		}
		if (abs(r_1 - r_2) < d)
		{
			cout << "There are only 2 of them...." << endl;
			long double c = x_2 * x_2 + y_2 * y_2 - r_2 * r_2;
			long double A = x_1 * x_1 + y_1 * y_1 - r_1 * r_1;
			long double B = c - 2 * x_2 * x_2 + 2 * x_1 * x_2 - A;
			long double q = 4 * (x_2 - x_1) * (x_2 - x_1) * (x_2 * x_2 - c);
			auto p = solve(-4 * d * d, 8 * (x_1 - x_2) * (x_1 - x_2) * y_2 - 4 * (y_1 - y_2) * B, q - B * B);
			long double x = x_2 + sqrt(x_2 * x_2 - p.first * p.first + 2 * p.first * y_2 - c);
			long double z = x_2 - sqrt(x_2 * x_2 - p.second * p.second + 2 * p.second * y_2 - c);
			if (x == z)
			{
				cout << fixed << setprecision(6) << x << " " << min(p.first, p.second) << endl;
				cout << fixed << setprecision(6) << z << " " << max(p.first, p.second) << endl << endl;
				return;
			}
			if (x < z)
			{
				cout << fixed << setprecision(6) << x << " " << p.first << endl;
				cout << fixed << setprecision(6) << z << " " << p.second << endl << endl;
				return;
			}
			else
			{
				cout << fixed << setprecision(6) << z << " " << p.second << endl;
				cout << fixed << setprecision(6) << x << " " << p.first << endl << endl;
				return;
			}
		}
	}
}

int main()
{
	int k;
	cin >> k;
	long double* x = new long double[2 * k];
	long double* y = new long double[2 * k];
	long double* r = new long double[2 * k];
	for (int i = 0; i < 2 * k; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
	}
	for (int i = 0; i < k; i++)
	{
		number(x[2 * i], y[2 * i], r[2 * i], x[2 * i + 1], y[2 * i + 1], r[2 * i + 1]);
	}
}
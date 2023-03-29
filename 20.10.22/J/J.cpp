#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void test(long double* x_1, long double* y_1, long double* x_2, long double* y_2, long double* x_3, long double* y_3, int i)
{
	pair <long double, long double> p_1 = make_pair(x_1[i], y_1[i]);
	pair <long double, long double> p_2 = make_pair(x_2[i], y_2[i]);
	pair <long double, long double> p_3 = make_pair(x_3[i], y_3[i]);
	pair <long double, long double> p_4 = make_pair(x_1[i + 1], y_1[i + 1]);
	pair <long double, long double> p_5 = make_pair(x_2[i + 1], y_2[i + 1]);
	pair <long double, long double> p_6 = make_pair(x_3[i + 1], y_3[i + 1]);
	if ((abs(y_1[i] - y_2[i]) < pow(10.0, -10) && abs(x_1[i] - x_2[i]) < pow(10.0, -10)) && (abs(x_1[i] - x_3[i]) < pow(10.0, -10) && abs(y_1[i] - y_3[i]) < pow(10.0, -10)))
	{
		if (p_4 == p_5 && p_4 == p_6)
		{
			cout << "YES" << endl;
			return;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	int count_1 = 0, count_2 = 0;
	if ((p_1 == p_2) || (p_2 == p_3) || (p_1 == p_3))
	{
		count_1 = 2;
	}
	if ((p_4 == p_5) || (p_4 == p_6) || (p_5 == p_6))
	{
		count_2 = 2;
	}
	if (count_1 == 2 && count_2 == 2)
	{
		cout << "YES" << endl;
		return;
	}
	if (count_1 == 2 || count_2 == 2)
	{
		cout << "NO" << endl;
		return;
	}
	long double d_12a = sqrt((x_1[i] - x_2[i]) * (x_1[i] - x_2[i]) + (y_1[i] - y_2[i]) * (y_1[i] - y_2[i]));
	long double d_23a = sqrt((x_2[i] - x_3[i]) * (x_2[i] - x_3[i]) + (y_2[i] - y_3[i]) * (y_2[i] - y_3[i]));
	long double d_13a = sqrt((x_1[i] - x_3[i]) * (x_1[i] - x_3[i]) + (y_1[i] - y_3[i]) * (y_1[i] - y_3[i]));
	long double d_12b = sqrt((x_1[i + 1] - x_2[i + 1]) * (x_1[i + 1] - x_2[i + 1]) + (y_1[i + 1] - y_2[i + 1]) * (y_1[i + 1] - y_2[i + 1]));
	long double d_23b = sqrt((x_2[i + 1] - x_3[i + 1]) * (x_2[i + 1] - x_3[i + 1]) + (y_2[i + 1] - y_3[i + 1]) * (y_2[i + 1] - y_3[i + 1]));
	long double d_13b = sqrt((x_1[i + 1] - x_3[i + 1]) * (x_1[i + 1] - x_3[i + 1]) + (y_1[i + 1] - y_3[i + 1]) * (y_1[i + 1] - y_3[i + 1]));
	long double k_1, k_2, k_3;
	if (abs(d_12b) < pow(10.0, -10))
	{
		if (abs(d_12a) < pow(10.0, -10))
		{
			k_1 = -1;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	else
	{
		k_1 = d_12a / d_12b;
	}
	if (abs(d_23b) < pow(10.0, -10))
	{
		if (abs(d_23a) < pow(10.0, -10))
		{
			k_2 = -1;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	else
	{
		k_2 = d_23a / d_23b;
	}
	if (abs(d_13b) < pow(10.0, -10))
	{
		if (abs(d_13a) < pow(10.0, -10))
		{
			k_3 = -1;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	else
	{
		k_3 = d_13a / d_13b;
	}
	if (abs(k_1 + 1) > pow(10.0, -10))
	{
		if (abs(k_2 + 1) > pow(10.0, -10))
		{
			if (abs(k_3 + 1) > pow(10.0, -10))
			{
				if (abs(k_1 - k_2) < pow(10.0, -10) && abs(k_1 - k_3) < pow(10.0, -10))
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
			else
			{
				if (abs(k_1  - k_2) < pow(10.0, -10))
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
		}
		else
		{
			if (abs(k_3 + 1) > pow(10.0, -10))
			{
				if (abs(k_1 - k_3) < pow(10.0, -10))
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
			else
			{
				cout << "YES" << endl;
			}
		}
	}
	else
	{
		if (abs(k_2 + 1) > pow(10.0, -10))
		{
			if (abs(k_3 + 1) > pow(10.0, -10))
			{
				if (abs(k_2 - k_3) < pow(10.0, -10))
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
		}
	}
}

int main()
{
	int c;
	cin >> c;
	long double* x_1 = new long double[2 * c];
	long double* y_1 = new long double[2 * c];
	long double* x_2 = new long double[2 * c];
	long double* y_2 = new long double[2 * c];
	long double* x_3 = new long double[2 * c];
	long double* y_3 = new long double[2 * c];
	for (int i = 0; i < c; i++)
	{
		cin >> x_1[2 * i] >> y_1[2 * i] >> x_2[2 * i] >> y_2[2 * i] >> x_3[2 * i] >> y_3[2 * i];
		cin >> x_1[2 * i + 1] >> y_1[2 * i + 1] >> x_2[2 * i + 1] >> y_2[2 * i + 1] >> x_3[2 * i + 1] >> y_3[2 * i + 1];
	}
	for (int i = 0; i < c; i++)
	{
		test(x_1, y_1, x_2, y_2, x_3, y_3, 2 * i);
	}
}

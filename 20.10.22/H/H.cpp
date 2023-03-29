#include <iostream>
#include <utility>
using namespace std;

void line(long double x_1, long double y_1, long double x_2, long double y_2, long double* a, long double* b, long double* c, int i)
{
	a[i] = y_2 - y_1;
	b[i] = x_1 - x_2;
	c[i] = -(a[i] * x_1 + b[i] * y_1);
}

bool in(long double x, long double y, long double x_1, long double y_1, long double x_2, long double y_2)
{
	long double ai = y_2 - y_1;
	long double bi = x_1 - x_2;
	long double ci = -(ai * x_1 + bi * y_1);
	if (x_1 == x_2 && y_1 == y_2)
	{
		if (x == x_1 && y == y_1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (ai * x + bi * y + ci == 0)
	{
		if (x_1 == x_2)
		{
			if (y >= min(y_1, y_2) && y <= max(y_1, y_2))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (x >= min(x_1, x_2) && x <= max(x_1, x_2))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

pair <int, int> test(long double a, long double b, long double c, long double x, long double y, long double x_0, long double y_0, int f, int g)
{
	int count = f;
	int k = g;
	if (a * x_0 + b * y_0 + c == 0)
	{
		k = -1;
	}
	else
	{
		if (a * x_0 + b * y_0 + c > 0)
		{
			if (a * x + b * y + c > 0)
			{
				count++;
			}
			else
			{
				if (a * x + b * y + c < 0)
				{
					;
				}
				else
				{
					k = 1;
					count++;
				}
			}
		}
		else
		{
			if (a * x + b * y + c < 0)
			{
				count++;
			}
			else
			{
				if (a * x + b * y + c > 0)
				{
					;
				}
				else
				{
					k = 1;
					count++;
				}
			}
		}
	}
	return make_pair(count, k);
}

int main()
{
	long double* a = new long double[3];
	long double* b = new long double[3];
	long double* c = new long double[3];
	long double x_1, y_1, x_2, y_2, x_3, y_3, x, y;
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x >> y;
	pair <long double, long double> p_1 = make_pair(x_1, y_1);
	pair <long double, long double> p_2 = make_pair(x_2, y_2);
	pair <long double, long double> p_3 = make_pair(x_3, y_3);
	if (p_1 == p_2)
	{
		if (p_2 == p_3)
		{
			if (x == x_1 && y == y_1)
			{
				cout << "BORDER";
				return 0;
			}
			else
			{
				cout << "OUTSIDE";
				return 0;
			}
		}
		else
		{
			if (in(x, y, x_2, y_2, x_3, y_3))
			{
				cout << "BORDER";
				return 0;
			}
			else
			{
				cout << "OUTSIDE";
				return 0;
			}
		}
	}
	else
	{
		if (p_2 == p_3)
		{
			if (in(x, y, x_1, y_1, x_2, y_2))
			{
				cout << "BORDER";
				return 0;
			}
			else
			{
				cout << "OUTSIDE";
				return 0;
			}
		}
		else
		{
			if (p_1 == p_3)
			{
				if (in(x, y, x_1, y_1, x_2, y_2))
				{
					cout << "BORDER";
					return 0;
				}
				else
				{
					cout << "OUTSIDE";
					return 0;
				}
			}
		}
	}
	line(x_1, y_1, x_2, y_2, a, b, c, 0);
	line(x_1, y_1, x_3, y_3, a, b, c, 1);
	line(x_2, y_2, x_3, y_3, a, b, c, 2);
	pair <int, int> p = test(a[0], b[0], c[0], x, y, x_3, y_3, 0, 0);
	p = test(a[1], b[1], c[1], x, y, x_2, y_2, p.first, p.second);
	p = test(a[2], b[2], c[2], x, y, x_1, y_1, p.first, p.second);
	int count = p.first;
	int k = p.second;
	//cout << count << " " << k << endl;
	if (k == -1)
	{
		if (in(x, y, x_1, y_1, x_2, y_2))
		{
			cout << "BORDER";
			return 0;
		}
		if (in(x, y, x_1, y_1, x_3, y_3))
		{
			cout << "BORDER";
			return 0;
		}
		if (in(x, y, x_2, y_2, x_3, y_3))
		{
			cout << "BORDER";
			return 0;
		}
		cout << "OUTSIDE";
		return 0;
	}
	else
	{
		if (count == 3)
		{
			if (k == 1)
			{
				cout << "BORDER";
				return 0;
			}
			else
			{
				cout << "INSIDE";
				return 0;
			}
		}
		else
		{
			cout << "OUTSIDE";
			return 0;
		}
	}
}
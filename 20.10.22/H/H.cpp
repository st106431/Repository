#include <iostream>
using namespace std;

void line(long double x_1, long double y_1, long double x_2, long double y_2, long double* a, long double* b, long double* c, int i)
{
	a[i] = y_2 - y_1;
	b[i] = x_1 - x_2;
	c[i] = -(a[i] * x_1 + b[i] * y_1);
}

int main()
{
	long double* a = new long double[3];
	long double* b = new long double[3];
	long double* c = new long double[3];
	long double x_1, y_1, x_2, y_2, x_3, y_3, x, y;
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x >> y;
	line(x_1, y_1, x_2, y_2, a, b, c, 0);
	line(x_1, y_1, x_3, y_3, a, b, c, 1);
	line(x_2, y_2, x_3, y_3, a, b, c, 2);
	int count = 0, k = 0;
	if (a[0] * x_3 + b[0] * y_3 + c[0] > 0)
	{
		if (a[0] * x + b[0] * y + c[0] > 0)
		{
			count++;
		}
		else
		{
			if (a[0] * x + b[0] * y + c[0] < 0)
			{
				cout << "OUTSIDE";
				return 0;
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
			if (a[0] * x + b[0] * y + c[0] > 0)
			{
				count++;
			}
			else
			{
				if (a[0] * x + b[0] * y + c[0] < 0)
				{
					cout << "OUTSIDE";
					return 0;
				}
				else
				{
					k = 1;
					count++;
				}
			}
	}
}
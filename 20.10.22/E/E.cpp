#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long double x, y, x_1, y_1, x_2, y_2;
	cin >> x >> y >> x_1 >> y_1 >> x_2 >> y_2;
	long double a = y_2 - y_1;
	long double b = x_1 - x_2;
	long double c = -(a * x_1 + b * y_1);
	if (x_1 == x_2 && y_1 == y_2)
	{
		if (x == x_1 && y == y_1)
		{
			cout << "YES";
			return 0;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	if (a * x + b * y + c == 0)
	{
		if (x_1 == x_2)
		{
			if (y >= min(y_1, y_2) && y <= max(y_1, y_2))
			{
				cout << "YES";
				return 0;
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		if (x >= min(x_1, x_2) && x <= max(x_1, x_2))
		{
			cout << "YES";
			return 0;
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	else
	{
		cout << "NO";
		return 0;
	}
}
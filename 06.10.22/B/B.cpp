#include <iostream>
using namespace std;
int k, d, n;

int gcd(int a, int b) 
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}

int in(long long x_1, long long y_1, long long x_2, long long y_2)
{
	k = 0;
	d = 0;
	long long x = x_1;
	n = (x_2 - x_1) / gcd(y_2 - y_1, x_2 - x_1);
	if (x < x_2)
	{
		while ((x <= x_2) && (d == 0))
		{
			if (((x - x_1) * (y_2 - y_1)) % (x_2 - x_1) == 0)
			{
				k++;
				d = 1;
			}
			x++;
		}
		if (d == 1)
		{
			if ((x_2 - x + 1) % n != 0)
			{
				return (x_2 - x + 1) / abs(n);
			}
			else
			{
				return (x_2 - x + 1) / abs(n) + 1;
			}
		}
	}
	else
	{
		while ((x >= x_2) && (d == 0))
		{
			if (((x - x_1) * (y_2 - y_1)) % (x_2 - x_1) == 0)
			{
				k++;
				d = 1;
			}
			x--;
		}
		if (d == 1)
		{
			if ((x + 1 - x_2) % n != 0)
			{
				return (x + 1 - x_2) / abs(n);
			}
			else
			{
				return (x + 1 - x_2) / abs(n) + 1;
			}
		}
	}
	return k;
}

int main()
{
	long long x_1, y_1, x_2, y_2;
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	if (x_1 == x_2)
	{
		cout << abs(y_1 - y_2) + 1;
		return 0;
	}
	if (y_1 == y_2)
	{
		cout << abs(x_1 - x_2) + 1;
		return 0;
	}
	
	cout << in(x_1, y_1, x_2, y_2);
}

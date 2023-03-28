#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4, a_1, b_1, c_1, a_2, b_2, c_2, x, y;
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3 >> x_4 >> y_4;
	a_1 = y_2 - y_1;
	b_1 = x_1 - x_2;
	c_1 = -(a_1 * x_1 + b_1 * y_1);
	a_2 = y_4 - y_3;
	b_2 = x_3 - x_4;
	c_2 = -(a_2 * x_3 + b_2 * y_3);
	if (b_2 * a_1 - b_1 * a_2 == 0)
	{
		if (b_2 * c_1 - b_1 * c_2 == 0 && a_2 * c_1 - a_1 * c_2 == 0)
		{
			if (x_1 > x_2)
			{
				swap(x_1, x_2);
			}
			if (x_3 > x_4)
			{
				swap(x_3, x_4);
			}
			if (y_1 > y_2)
			{
				swap(y_1, y_2);
			}
			if (y_3 > y_4)
			{
				swap(y_3, y_4);
			}
			if (max(x_2, x_4) == min(x_1, x_3))
			{
				if (max(y_2, y_4) == min(y_1, y_3))
				{
					cout << fixed << setprecision(9) << x_2 << " " << y_2;
					return 0;
				}
				else
				{
					if (y_2 > y_4)
					{
						if (y_1 > y_3)
						{
							if (y_1 > y_4)
							{
								cout << "Empty";
								return 0;
							}
							else
							{
								cout << fixed << setprecision(9) << x_2 << " " << y_1 << endl;
								cout << fixed << setprecision(9) << x_2 << " " << y_4;
								return 0;
							}
						}
						else
						{
							cout << fixed << setprecision(9) << x_2 << " " << y_3 << endl;
							cout << fixed << setprecision(9) << x_2 << " " << y_4;
							return 0;
						}
					}
				}
			}
			if (min(x_1, x_2))
			{

			}
			return 0;
		}
		else
		{
			cout << "Empty";
			return 0;
		}
	}
	x = -(b_2 * c_1 - b_1 * c_2) / (b_2 * a_1 - b_1 * a_2);
	y = -(a_2 * c_1 - a_1 * c_2) / (a_2 * b_1 - a_1 * b_2);
	cout << fixed << setprecision(9) << x << " ";
	cout << fixed << setprecision(9) << y;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b, x_1, x_2;
	cin >> a >> b >> x_1 >> x_2;
	double frac = 1.0 / b;
	if (x_1 > x_2)
	{
		cout << fixed << setprecision(10) << a + frac;
		return 0;
	}
	else
	{
		cout << fixed << setprecision(10) << -(a + frac);
		return 0;
	}
}